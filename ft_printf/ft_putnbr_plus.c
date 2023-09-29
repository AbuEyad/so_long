/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_plus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:22:07 by habu-zua          #+#    #+#             */
/*   Updated: 2023/08/21 11:43:58 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_plus(int n)
{
	int		count;
	char	*s;

	count = 0;
	s = ft_itoa(n);
	count = ft_putstr_plus(s);
	free(s);
	return (count);
}
