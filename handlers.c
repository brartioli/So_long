/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 19:20:01 by bfernan2          #+#    #+#             */
/*   Updated: 2025/12/04 17:17:56 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_images(t_game *game);
static void	free_and_close(t_game *game);

int	exit_game(t_game *game)
{
	destroy_images(game);
	free_and_close(game);
	exit (0);
	return (0);
}

static void	destroy_images(t_game *game)
{
	void	*images[6];
	int		i;

	images[0] = game->img.wall;
	images[1] = game->img.floor;
	images[2] = game->img.player;
	images[3] = game->img.collectible;
	images[4] = game->img.exit;
	images[5] = NULL;
	i = 0;
	while (images[i])
	{
		mlx_destroy_image(game->mlx_ptr, images[i]);
		i++;
	}
}

static void	free_and_close(t_game *game)
{
	if (game->buffer)
		mlx_destroy_image(game->mlx_ptr, game->buffer);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	if (game->map.map)
		free_map(game->map.map, game->map.height);
}

void	handle_collectible(t_game *game, int x, int y)
{
	game->collected++;
	game->map.map[y][x] = '0';
	if (game->collected < game->map.collectibles)
		ft_printf("\nYou've found a treasure! Only %d to go!\n\n",
			game->map.collectibles - game->collected);
	else
		ft_printf("\nYou collected all itens.\n\n");
}

int	handle_exit(t_game *game)
{
	ft_printf("\nCongrats, you win!\n\n");
	exit_game(game);
	return (1);
}
