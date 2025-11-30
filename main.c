/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmfanfa <tmfanfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:02:26 by bfernan2          #+#    #+#             */
/*   Updated: 2025/11/30 17:03:20 by tmfanfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->map.map = NULL;
	game->buffer = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->map.player_count = 0;
	game->map.collectibles = 0;
	game->map.exit_count = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.moves = 0;
	game->collected = 0;
	game->img.wall = NULL;
	game->img.floor = NULL;
	game->img.player = NULL;
	game->img.collectible = NULL;
	game->img.exit = NULL;
}

static void	setup_game(t_game *game)
{
	find_player_position(game);
	mlx_hook(game->win_ptr, 17, 0, exit_game, game);
	mlx_key_hook(game->win_ptr, key_hook, game);
	render(game);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;

	init_game(&game);
	if (!args_are_valid(argc, argv, &fd)
		|| !read_map(&game, fd)
		|| !validate_map(&game)
		|| !init_mlx(&game)
		|| !load_assets(&game))
	{
		//free_game(&game);
		return (1);
	}
	ft_printf("\nYour game just start, enjoy it\n");
	setup_game(&game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
