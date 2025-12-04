/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 14:12:45 by bfernan2          #+#    #+#             */
/*   Updated: 2025/12/04 17:31:56 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_horizontal_walls(t_game *game, int width)
{
	int	i;

	i = 0;
	while (i < width - 1)
	{
		if (game->map.map[0][i] != '1' ||
			game->map.map[game->map.height - 1][i] != '1')
		{
			ft_printf ("Error - Map incomplete. Horrizontal Walls!\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_reachable_items(char **map_copy, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (map_copy[i][j])
		{
			if ((game->map.map[i][j] == 'C' || game->map.map[i][j] == 'E') &&
				map_copy[i][j] != 'F')
			{
				ft_printf("Error - Invalid path!\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	free_map_copy(char **map_copy, int heigth)
{
	int	i;

	i = 0;
	while (i < heigth)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}
