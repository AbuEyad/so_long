/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:14:01 by habu-zua          #+#    #+#             */
/*   Updated: 2023/09/29 16:05:02 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include "../minilibx/mlx.h"

typedef struct s_point 
{
	int	j;
	int	i;
}	t_point;

typedef struct t_start
{
	int		fd;
	int		hightmap;
	int		widthmap;
	int		p_count;
	int		c_count;
	int		e_count;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		collectables;
	char	**map;
	void	*floor;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;
	t_point	player_pos;

}	t_game;

int		exit_point(t_game *game);
int		map_reading(t_game *game, char **argv);
int		controls_working(int command, t_game *game);
void	placing_graphics(t_game *game);
void	images_assignment(t_game *game);
void	check_errors(t_game *game);
void	flood_fill(t_game *game, char **map, t_point p, char to_fill);
int		ft_flood_check(char **map);
void	ft_free(char **map);
int		ft_rectangular(char **map);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_check_map_file(char *map_file);
int		ft_check_images(void);
int		is_valid(char c);

#endif
