/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:38:12 by bfernan2          #+#    #+#             */
/*   Updated: 2025/11/13 20:40:38 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	args_are_valid(int argc, char **argv, int *fd)
{
	if (argc != 2)
	{
		ft_printf("Error - no Map\n");
		return (0);
	}
	*fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error - invalid map\n");
		return (0);
	}
	return (1);
}


