/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:01:01 by bfernan2          #+#    #+#             */
/*   Updated: 2025/12/04 17:17:28 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int x, int y, int height)
{
	const int	dx[] = {1, -1, 0, 0};
	const int	dy[] = {0, 0, 1, -1};
	int			i;

	if (!is_valid_position(map, x, y, height))
		return ;
	map[y][x] = 'F';
	i = 0;
	while (i < 4)
	{
		flood_fill(map, x + dx[i], y + dy[i], height);
		i++;
	}
}

int	is_valid_position(char **map, int x, int y, int heigth)
{
	return (x >= 0 && y >= 0 && y < heigth && map[y] != NULL
		&& x < (int)ft_strlen(map[y])
		&& map[y][x] != '1' && map[y][x] != 'F');
}
