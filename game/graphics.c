/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:13:13 by habu-zua          #+#    #+#             */
/*   Updated: 2023/09/29 15:57:00 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	images_assignment(t_game *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"images/floor.xpm", &i, &j);
	game->barrier = mlx_xpm_file_to_image(game->mlxpointer,
			"images/wall.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"images/player.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer,
			"images/exit.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlxpointer,
			"images/item.xpm", &i, &j);
	if (!game->floor || !game->barrier || !game->player \
		|| !game->exit || !game->collectable)
	{
		ft_printf("Error\ncan't open/read images.\n");
		exit_point(game);
	}
}

void	place_player(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlxpointer, 
		game->winpointer, game->player, j * 32, i * 32);
	game->y_axis = i;
	game->x_axis = j;
}

void	place_collectable(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlxpointer, 
		game->winpointer, game->collectable, j * 32, i * 32);
	game->collectables++;
}

void	place_floor(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlxpointer, 
		game->winpointer, game->floor, j * 32, i * 32);
}

void	placing_graphics(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->hightmap)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlxpointer, 
					game->winpointer, game->barrier, j * 32, i * 32);
			if (game->map[i][j] == 'C')
				place_collectable(game, i, j);
			if (game->map[i][j] == 'P')
				place_player(game, i, j);
			if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlxpointer, 
					game->winpointer, game->exit, j * 32, i * 32);
			if (game->map[i][j] == '0')
				place_floor(game, i, j);
			j++;
		}
		i++;
	}
}
