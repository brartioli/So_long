/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:02:26 by bfernan2          #+#    #+#             */
/*   Updated: 2025/11/13 20:45:52 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->map.map = NULL;
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

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;
	
	init_game(&game);
	if (!args_are_valid(argc, argv, &fd) 
		|| !read_map(&game, fd) 
		|| !validete_map(&game)
		|| !init_mlx(&game)
		|| !load_images(&game))
	{
		free_game(&game);
		return (1);
	}
	ft_printf("\nYour game just start, enjoy it\n");
	setup_hooks(&game);
	render_map(&game);
	mlx_loop(game.mlx_ptr);
}
