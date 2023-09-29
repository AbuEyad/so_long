/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:01:45 by habu-zua          #+#    #+#             */
/*   Updated: 2023/09/29 10:24:18 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	flood_fill(t_game *game, char **map, t_point p, char to_fill)
{
	if (p.i > game->widthmap || p.j > game->hightmap 
		|| (map[p.j][p.i] != to_fill && map[p.j][p.i] != 'C'))
		return ;
	map[p.j][p.i] = 'F';
	flood_fill(game, map, (t_point){p.j - 1, p.i}, to_fill);
	flood_fill(game, map, (t_point){p.j + 1, p.i}, to_fill);
	flood_fill(game, map, (t_point){p.j, p.i - 1}, to_fill);
	flood_fill(game, map, (t_point){p.j, p.i + 1}, to_fill);
}

int	ft_flood_check(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C' || map[j][i] == 'E' || map[j][i] == 'P')
			{
				if (!(is_valid(map[j][i + 1]) || is_valid(map[j][i - 1]) \
				|| is_valid(map[j + 1][i]) || is_valid(map[j - 1][i])))
					return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}

void	ft_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	ft_rectangular(char **map)
{
	int	widthmap;
	int	i;
	int	j;

	widthmap = ft_strlen(map[0]);
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i] != '\n' && map[j][i])
			i++;
		if (i != widthmap - 1)
			return (0);
		j++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < len)
		{
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
