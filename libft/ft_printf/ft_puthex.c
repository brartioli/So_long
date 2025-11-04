/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:59:42 by bfernan2          #+#    #+#             */
/*   Updated: 2025/08/11 14:39:42 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_puthex(unsigned long n, char x)
{
	char	*base;
	int		count;

	count = 0;
	if (x == 'x')
		base = "0123456789abcdef";
	else if (x == 'X')
		base = "0123456789ABCDEF";
	else
		return (0);
	if (n > 15)
		count += ft_puthex(n / 16, x);
	count += ft_putchar(base[n % 16]);
	return (count);
}
