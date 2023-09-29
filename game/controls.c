/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:13:00 by habu-zua          #+#    #+#             */
/*   Updated: 2023/09/29 16:04:06 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	right_move(t_game *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		ft_printf("\nYou Have Won, Congrats!\n");
		exit_point(game);
	}
	if (game->map[j][i] == '0' 
		|| game->map [j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->counter++;
		if (game->map[j][i] == 'C')
			game->counter++;
	}
	return (1);
}

static int	up_down(t_game *game, int movement)
{
	int	i;
	int	j;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == 126)
	{
		j--;
		if (game->map[j][i] == '1' || !right_move(game, i, j))
			return (0);
		game->map[j + 1][i] = '0';
	}
	else if (movement == 125)
	{
		j++;
		if (game->map[j][i] == '1' || !right_move(game, i, j))
			return (0);
		game->map[j - 1][i] = '0';
	}
	ft_printf("Steps Taken: %i\n", game->counter);
	ft_printf("Collectables Remaining: %i\n", game->collectables);
	return (1);
}

static int	lift_right(t_game *game, int movement)
{
	int	i;
	int	j;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == 123)
	{
		i--;
		if (game->map[j][i] == '1' || !right_move(game, i, j))
			return (0);
		game->map[j][i + 1] = '0';
	}
	else if (movement == 124)
	{
		i++;
		if (game->map[j][i] == '1' || !right_move(game, i, j))
			return (0);
		game->map[j][i - 1] = '0';
	}
	ft_printf("Steps Taken: %i\n", game->counter);
	ft_printf("Collectables Remaining: %i\n", game->collectables);
	return (1);
}

int	controls_working(int command, t_game *game)
{
	int	move;

	move = 0;
	if (command == 53)
		exit_point(game);
	if (command == 125 || command == 126)
		move = up_down(game, command);
	else if (command == 123 || command == 124)
		move = lift_right(game, command);
	if (move)
	{
		game->collectables = 0;
		placing_graphics(game);
	}
	return (1);
}
