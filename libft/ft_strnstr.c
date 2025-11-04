/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:44:16 by bfernan2          #+#    #+#             */
/*   Updated: 2025/08/07 09:45:40 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	size_t	i;
	size_t	j;

	j = 0;
	b = (char *)big;
	while (little[j])
		j++;
	if (j == 0)
		return (b);
	while (*b && len > 0 && j <= len)
	{
		i = 0;
		while (little[i] == b[i] && little[i])
			i++;
		if (!little[i])
			return (b);
		len--;
		b++;
	}
	return ((char *)0);
}
