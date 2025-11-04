/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:56:07 by bfernan2          #+#    #+#             */
/*   Updated: 2025/08/12 14:59:08 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	p;
	int				count;

	count = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	p = (unsigned long)ptr;
	count += ft_putstr("0x");
	count += ft_puthex(p, 'x');
	return (count);
}
