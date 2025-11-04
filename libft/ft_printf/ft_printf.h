/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:08:12 by bfernan2          #+#    #+#             */
/*   Updated: 2025/08/12 17:06:25 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int				ft_putchar(int c);
int				ft_putstr(const char *str);
int				ft_printf(const char *format, ...);
int				ft_putptr(void *ptr);
int				ft_puthex(unsigned long n, char x);
int				ft_putnbr(int nb);
unsigned int	ft_unsigned_putnbr(unsigned int nb);
#endif