/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:12:19 by bfernan2          #+#    #+#             */
/*   Updated: 2025/08/12 17:05:53 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

unsigned int	ft_unsigned_putnbr(unsigned int nb)
{
	unsigned long	nbl;
	int				count;

	count = 0;
	nbl = nb;
	if (nbl >= 10)
	{
		count += ft_unsigned_putnbr(nbl / 10);
		count += ft_unsigned_putnbr(nbl % 10);
	}
	else
	{
		count += ft_putchar(nbl + 48);
	}
	return (count);
}
