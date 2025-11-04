/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:01:18 by bfernan2          #+#    #+#             */
/*   Updated: 2025/09/18 19:53:22 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static int	arg_conversion(va_list args, const char conversion)
{
	int	count;

	count = 0;
	if (conversion == 's')
		count += ft_putstr(va_arg(args, const char *));
	else if (conversion == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (conversion == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (conversion == 'd')
		count += ft_putnbr(va_arg(args, int));
	else if (conversion == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (conversion == 'u')
		count += ft_unsigned_putnbr(va_arg(args, unsigned int));
	else if (conversion == 'x')
		count += ft_puthex(va_arg(args, unsigned int), 'x');
	else if (conversion == 'X')
		count += ft_puthex(va_arg(args, unsigned int), 'X');
	else if (conversion == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1])
		{
			len += arg_conversion(args, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
