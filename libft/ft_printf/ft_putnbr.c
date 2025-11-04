/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:03:22 by bfernan2          #+#    #+#             */
/*   Updated: 2025/08/12 14:57:31 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_putnbr(int nb)
{
	long	nbl;
	int		count;

	nbl = nb;
	count = 0;
	if (nbl < 0)
	{
		ft_putchar('-');
		nbl = -nbl;
		count++;
	}
	if (nbl >= 10)
	{
		count += ft_putnbr(nbl / 10);
		count += ft_putnbr(nbl % 10);
	}
	else
		count += ft_putchar(nbl + 48);
	return (count);
}
