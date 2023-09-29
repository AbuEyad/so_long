/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 21:43:54 by habu-zua          #+#    #+#             */
/*   Updated: 2023/08/21 15:53:14 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*uitoa(unsigned int n);

int	ft_put_u_int(unsigned int n)
{
	int		length;
	char	*num;

	length = 0;
	if (n == 0)
		length += write(1, "0", 1);
	else
	{
		num = uitoa(n);
		length += ft_putstr_plus(num);
		free(num);
	}
	return (length);
}

static char	*uitoa(unsigned int n)
{
	char			*num;
	int				len;
	unsigned int	nbr;

	len = 0;
	nbr = n;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 10;
	}
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (num);
}
