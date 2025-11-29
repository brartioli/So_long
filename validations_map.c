/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:25:37 by bfernan2          #+#    #+#             */
/*   Updated: 2025/11/29 15:11:59 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	validate_walls(t_game *game)
{
	int	width;

	width = ft_strlen(game->map.map[0]);
	return (check_vertical_walls(game, width)
		&& check_horizontal_walls(game, width));
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

int	validate_player(t_game *game)
{
	int	player_count;

	find_player(game, &player_count);
	if (player_count < 1)
	{
		ft_printf("Error - No player");
		return (0);
	}
	else if (player_count > 1)
	{
		ft_printf("Error - More than 1 player in game");
		return (0);
	}
	return (1);
}

int	validate_path(t_game *game)
{
	char	**map_copy;
	int		valid;

	map_copy = creat_map_copy(game);
	if (!map_copy)
	{
		ft_printf("Failed to allocate memory for map copy.\n");
		return (0);
	}
	flood_fill(map_copy, game->player.x, game->player.y, game->map.height);
	valid = check_reachable_items(map_copy, game);
	free_map_copy(map_copy, game->map.height);
	return (valid);
}