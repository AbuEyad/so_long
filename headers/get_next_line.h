/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:44:28 by habu-zua          #+#    #+#             */
/*   Updated: 2023/09/17 11:03:52 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  1000
# endif

# ifndef MAX_FD
#  define MAX_FD 1025
# endif

int		found_line(char *str, char c);
char	*return_remaining_txt(char *read_txt);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *read_txt, char *tmp_txt);
char	*return_line(char *read_txt);
char	*read_file(int fd, char *read_txt);
char	*get_next_line(int fd);

#endif