/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:13:06 by habu-zua          #+#    #+#             */
/*   Updated: 2023/09/24 13:12:11 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	check_walls(t_game *game)
{
	int	j;

	j = 0;
	while (j < game->widthmap)
	{
		if (!(game->map[0][j] == '1' && 
			game->map[game->hightmap - 1][j] == '1'))
			return (0);
		j++;
	}
	j = 1;
	while (j < game->hightmap - 1)
	{
		if (!(game->map[j][0] == '1' && 
			game->map[j][game->widthmap - 1] == '1'))
			return (0);
		j++;
	}
	return (1);
}

static	int	ft_paths(t_game *game)
{
	int		i;
	int		j;
	char	**map3;

	map3 = (char **)malloc(sizeof(char *) * (game->hightmap + 1));
	map3[game->hightmap] = NULL;
	j = 0;
	while (j < game->hightmap)
	{
		map3[j] = (char *)malloc(sizeof(char) * ft_strlen(game->map[j]) + 1);
		i = 0;
		while (i <= game->widthmap + 1)
		{
			map3[j][i] = game->map[j][i];
			i++;
		}
		j++;
	}
	map3[game->player_pos.j][game->player_pos.i] = '0';
	flood_fill(game, map3, game->player_pos, '0');
	map3[game->player_pos.j][game->player_pos.i] = 'P';
	i = ft_flood_check(map3);
	ft_free(map3);
	return (i);
}

static void	count_checker(t_game *game, int i, int j)
{
	if (game->map[i][j] != '1' &&
		game->map[i][j] != '0' &&
		game->map[i][j] != 'P' &&
		game->map[i][j] != 'E' &&
		game->map[i][j] != 'C' &&
		game->map[i][j] != '\n')
	{
		ft_printf("Error\n Not valid map character!%c\n", game->map[i][j]);
		exit_point(game);
	}
	if (game->map[i][j] == 'C')
		game->c_count++;
	if (game->map[i][j] == 'P')
	{
		game->p_count++;
		game->player_pos.i = j;
		game->player_pos.j = i;
	}
	if (game->map[i][j] == 'E')
		game->e_count++;
}

static	void	character_valid(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (i < game->hightmap - 1)
	{
		j = 1;
		while (j <= game->widthmap)
		{
			count_checker(game, i, j);
			j++;
		}
		i++;
	}
	if (!(game->p_count == 1 && game->c_count >= 1
			&& game->e_count == 1))
	{
		ft_printf("Error\nEither player, exit or collectable issue\n");
		exit_point(game);
	}
}

void	check_errors(t_game *game)
{
	character_valid(game);
	if (!check_walls(game))
	{
		ft_printf("Error\nThis map is missing the walls\n");
		exit_point(game);
	}
	else if (!ft_rectangular(game->map))
	{
		ft_printf("Error\nThis map is not rectangular\n");
		exit_point(game);
	}
	else if (!ft_paths(game))
	{
		ft_printf("Error\nThere is no path to the exit or to the collectables.");
		exit_point(game);
	}
}
