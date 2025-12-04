/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 20:50:54 by bfernan2          #+#    #+#             */
/*   Updated: 2025/12/04 17:22:46 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_tile(t_game *game, int x, int y, char tile_type)
{
	int	px;
	int	py;

	px = x * 32;
	py = y * 32;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img.floor, px, py);
	if (tile_type == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.wall, px, py);
	else if (tile_type == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.collectible, px, py);
	else if (tile_type == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.exit, px, py);
}

void	render_tile_at_position(t_game *game, char **map_copy, int x, int y)
{
	if (map_copy[y][x] == 'F')
		render_tile(game, x, y, game->map.map[y][x]);
	else if (game->map.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.wall, x * 32, y * 32);
}

void	update_player_tile_and_sync(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img.player, game->player.x * 32, game->player.y * 32);
}

void	render(t_game *game)
{
	char	**map_copy;
	int		x;
	int		y;

	map_copy = creat_map_copy(game);
	flood_fill(map_copy, game->player.x, game->player.y, game->map.height);
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			render_tile_at_position(game, map_copy, x, y);
			x++;
		}
		y++;
	}
	update_player_tile_and_sync(game);
	free_map(map_copy, game->map.height);
}
