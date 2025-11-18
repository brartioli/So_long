/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:25:37 by bfernan2          #+#    #+#             */
/*   Updated: 2025/11/17 20:53:14 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	validate_collectibles(t_game *game)
{
	int	collectible_count;

	count_collectibles(game, &collectible_count);
	if (collectible_count == 0)
	{
		ft_printf("Error - No collectibles found\n");
		return (0);
	}
	game->map.collectibles = collectible_count;
	game->collected = 0;
	return (1);
}

int	validate_rectangle(t_game *game)
{
	int	i;
	int	width;

	i = 1;
	if (!game->map.map || game->map.height == 0)
		return (ft_printf("Error - Empty map\n"));
	width = ft_strlen(game->map.map[0]);
	while (i < game->map.height)
	{
		if ((int)ft_strlen(game->map.map[i]) != width)
		{
			ft_printf("Error - Map is not rectangular\n");
			return (0);
		}
		i++;
	}
	game->map.width = width;
	return (1);
}
