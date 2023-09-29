/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:17:00 by habu-zua          #+#    #+#             */
/*   Updated: 2023/09/17 13:07:28 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_check_map_file(char *map_file)
{
	int		fd;
	char	*i;

	i = ft_strnstr(map_file, ".ber", ft_strlen(map_file));
	if (!i || ft_strlen(i) > 4)
		return (0);
	fd = open(map_file, O_RDONLY);
	if (fd == -1 || read(fd, NULL, 0) == -1)
		return (0);
	close (fd);
	return (1);
}

int	check_file(char *file)
{
	int		fd;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * 1);
	fd = open(file, O_RDONLY);
	if (fd == -1 || read(fd, buff, 1) != 1)
	{
		free(buff);
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	ft_check_images(void)
{
	if (!check_file("images/exit.xpm") || !check_file("images/floor.xpm") \
		|| !check_file("images/item.xpm") || !check_file("images/player.xpm") \
		|| !check_file("images/wall.xpm"))
		return (0);
	return (1);
}
