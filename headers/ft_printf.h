/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:18:16 by habu-zua          #+#    #+#             */
/*   Updated: 2023/09/29 15:47:07 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		ft_putnbr_plus(int n);
int		ft_putstr_plus(char *s);
int		ft_putchar_plus(int c);
int		put_hex(unsigned int num, const char format);
int		ft_put_u_int(unsigned int n);
int		ft_put_ptr(unsigned long ptr);
char	*ft_itoa(int n);
#endif