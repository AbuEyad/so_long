/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:13:27 by habu-zua          #+#    #+#             */
/*   Updated: 2023/09/29 16:04:38 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	ft_memset(void *b, int c, size_t length)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (length--)
		*p++ = (unsigned char)c;
	return ;
}

int	exit_point(t_game *game)
{
	int	line;

	line = 0;
	if (game->winpointer)
		mlx_destroy_window(game->mlxpointer, game->winpointer);
	free(game->mlxpointer);
	while (line < game->hightmap - 1)
		free(game->map[line++]);
	free(game->map);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error\n not enough/or more arguments\n");
		return (0);
	}
	else if (ft_check_map_file(argv[1]) == 0 || ft_check_images() == 0) 
	{
		ft_printf("Error\n can't open/read map or images.\n");
		return (0);
	}
	ft_memset(&game, 0, sizeof(t_game));
	map_reading(&game, argv);
	check_errors(&game);
	game.mlxpointer = mlx_init();
	game.winpointer = mlx_new_window(game.mlxpointer, (game.widthmap * 32),
			(game.hightmap * 32), "solong");
	images_assignment(&game);
	placing_graphics(&game);
	mlx_hook(game.winpointer, 2, 1L << 0, controls_working, &game);
	mlx_hook(game.winpointer, 17, 0, exit_point, &game);
	mlx_loop(game.mlxpointer);
}
