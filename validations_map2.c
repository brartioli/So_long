/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_map2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 14:45:40 by bfernan2          #+#    #+#             */
/*   Updated: 2025/11/29 16:02:53 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	validate_exit(t_game *game)
{
	int	exit_count;
	int	i;
	int	j;

	exit_count = 0;
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < (int)ft_strlen(game->map.map[i]))
		{
			if (game->map.map[i][j] == 'E')
				exit_count++;
			j++;
		}
		i++;
	}
	if (exit_count != 1)
	{
		ft_printf("Error - no exit\n");
		return (0);
	}
	return (1);
}

int	validate_map_characters(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] != 'E' && map[y][x] != 'P' &&
				map[y][x] != 'C' && map[y][x] != '1' &&
				map[y][x] != '0' && map[y][x] != '\n')
			{
				ft_printf("Error - Undentified character.\n", map[y][x]);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
