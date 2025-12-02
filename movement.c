/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 19:45:22 by bfernan2          #+#    #+#             */
/*   Updated: 2025/12/02 18:01:05 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	key_hook(int keycode, t_game *game)
{
	int		new_x;
	int		new_y;
	char	next_tile;

	if (keycode == 65307 || keycode == 113)
		exit_game(game);
	get_new_position(keycode, &new_x, &new_y, game);
	if (!is_valid_move(new_x, new_y, game))
		return (0);
	next_tile = game->map.map[new_y][new_x];
	if (next_tile == 'C')
		handle_collectible(game, new_x, new_y);
	else if (next_tile == 'E')
	{
		if (!handle_exit(game))
			return (0);
	}
	if (new_x != game->player.x || new_y != game->player.y)
	{
		game->player.x = new_x;
		game->player.y = new_y;
		game->player.moves++;
		ft_printf("Movements: %d\n", game->player.moves);	
	}
	render(game);
	return (0);
}

void	get_new_position(int keycode, int *new_x, int *new_y, t_game *game)
{
	*new_x = game->player.x;
	*new_y = game->player.y;

	if (keycode == 's' || keycode == 653664)
		(*new_y)++;
	else if (keycode == 'a' || keycode == 65361)
		(*new_x)--;
	else if (keycode == 'w' || keycode == 65362)
		(*new_y)--;
	else if (keycode == 'd' || keycode == 65363)
		(*new_x)++;		
}

int	is_valid_move(int new_x, int new_y, t_game *game)
{
	char	next_tile;

	if (new_y < 0 || new_y >= game->map.height
		|| new_x < 0 || new_x >= game->map.width)
		return (0);
	next_tile = game->map.map[new_y][new_x];
	if (next_tile == '1')
		return (0);
	if (next_tile == 'E' && game->collected != game->map.collectibles)
	{
		ft_printf("You haven't collected all the collectibles yet\n",
				game->map.collectibles - game->collected);
		return (0);
	}
	return (1);
}