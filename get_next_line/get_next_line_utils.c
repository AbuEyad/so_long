/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:45:10 by habu-zua          #+#    #+#             */
/*   Updated: 2023/09/17 11:03:32 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*return_line(char *read_txt)
{
	int		i;
	char	*line_txt;

	i = 0;
	if (!read_txt[0])
		return (NULL);
	while (read_txt[i] && read_txt[i] != '\n')
		i++;
	line_txt = (char *)malloc(sizeof(char) * (i + 2));
	if (!line_txt)
		return (NULL);
	i = 0;
	while (read_txt[i] && read_txt[i] != '\n')
	{
		line_txt[i] = read_txt[i];
		i++;
	}
	if (read_txt[i] == '\n')
	{
		line_txt[i] = read_txt[i];
		i++;
	}
	line_txt[i] = '\0';
	return (line_txt);
}

int	found_line(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*return_remaining_txt(char *read_txt)
{
	int		i;
	int		j;
	char	*rem_txt;

	i = 0;
	while (read_txt[i] && read_txt[i] != '\n')
		i++;
	if (!read_txt[i])
	{
		free(read_txt);
		return (NULL);
	}
	rem_txt = (char *)malloc(sizeof(char) * (ft_strlen(read_txt) - i + 1));
	if (!rem_txt)
		return (NULL);
	i++;
	if (!read_txt[i])
		return (free(read_txt), free(rem_txt), NULL);
	j = 0;
	while (read_txt[i])
		rem_txt[j++] = read_txt[i++];
	rem_txt[j] = '\0';
	free(read_txt);
	return (rem_txt);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	int		i;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_str)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		new_str[i] = s1[i];
	while (*s2 != '\0')
		new_str[i++] = *s2++;
	new_str[i] = '\0';
	free (s1);
	return (new_str);
}
