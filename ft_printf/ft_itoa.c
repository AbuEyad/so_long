/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 22:01:36 by habu-zua          #+#    #+#             */
/*   Updated: 2023/08/21 11:32:51 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	out(char *s, int len, long n)
{
	*(s + len) = '\0';
	len--;
	while (n > 0)
	{
		*(s + len) = n % 10 + '0';
		n /= 10;
		len--;
	}
	if (len == 0 && s[1] == '\0')
		*s = '0';
	else if (len == 0 && s[1] != '\0')
		*s = '-';
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	size_t	size;

	nbr = n;
	size = 0;
	if (n <= 0)
	{
		size = 1;
		nbr = -nbr;
	}
	while (n)
	{
		n /= 10;
		size++;
	}
	str = (char *)malloc(size + 1);
	if (!str)
		return (0);
	out(str, size, nbr);
	return (str);
}
