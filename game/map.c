/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:13:20 by habu-zua          #+#    #+#             */
/*   Updated: 2023/09/29 10:23:08 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	is_valid(char c)
{
	return (c == 'F' || c == 'C' || c == 'E' || c == 'P');
}

static int	width_of_map(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\0')
		width++;
	if (string[width - 1] == '\n')
		width--;
	return (width);
}

static int	add_line(t_game *game, char *line)
{
	char	**temporary;
	int		i;

	if (!line || line[0] == '\0' || line[0] == '\n')
		return (0);
	i = 0;
	game->hightmap++;
	if (game->hightmap > 100)
	{
		ft_printf("Error\nMap is too big\n");
		exit_point(game);
	}
	temporary = (char **)malloc(sizeof(char *) * (game->hightmap + 1));
	temporary[game->hightmap] = NULL;
	while (i < game->hightmap - 1)
	{
		temporary[i] = game->map[i];
		i++;
	}
	temporary[i] = line;
	if (game->map)
		free(game->map);
	game->map = temporary;
	return (1);
}

int	map_reading(t_game *game, char **argv)
{
	char	*readmap;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	while (1)
	{
		readmap = get_next_line(game->fd);
		if (!add_line(game, readmap))
			break ;
	}
	close (game->fd);
	if (!game->map)
	{
		ft_printf("Error\nMap is empty\n");
		exit_point(game);
	}
	game->widthmap = width_of_map(game->map[0]);
	return (1);
}
