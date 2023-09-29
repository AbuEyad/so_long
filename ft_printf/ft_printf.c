/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:20:49 by habu-zua          #+#    #+#             */
/*   Updated: 2023/09/29 15:47:42 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	output(char c, va_list arglist)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar_plus(va_arg(arglist, int));
	else if (c == 's')
		count += ft_putstr_plus(va_arg(arglist, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr_plus(va_arg(arglist, int));
	else if (c == 'u')
		count += ft_put_u_int(va_arg(arglist, unsigned int));
	else if (c == 'p')
		count += ft_put_ptr(va_arg(arglist, unsigned long));
	else if (c == 'x' || c == 'X')
		count += put_hex(va_arg(arglist, unsigned int), c);
	else if (c == '%')
		count += ft_putchar_plus('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	arglist;

	count = 0;
	va_start(arglist, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			count += output(*(format + 1), arglist);
			format++;
		}
		else
		{
			ft_putchar_plus(*format);
			count++;
		}
		format++;
	}
	va_end(arglist);
	return (count);
}
