/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 21:39:50 by habu-zua          #+#    #+#             */
/*   Updated: 2023/08/21 15:35:17 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_len(unsigned	int n);

int	put_hex(unsigned int n, const char format)
{
	if (n == 0)
		return (write(1, "0", 1));
	else if (n >= 16)
	{
		put_hex(n / 16, format);
		put_hex(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_putchar_plus((n + '0'));
		else
		{
			if (format == 'x')
				ft_putchar_plus((n - 10 + 'a'));
			if (format == 'X')
				ft_putchar_plus((n - 10 + 'A'));
		}
	}
	return (hex_len(n));
}

static int	hex_len(unsigned	int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}
