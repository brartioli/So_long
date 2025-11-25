/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:07:25 by bfernan2          #+#    #+#             */
/*   Updated: 2025/11/24 20:59:54 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	initialize_window(t_game *game)
{
	int	window_width;
	int	window_heigth;

	window_width = game->map.width * 64;
	window_heigth = game->map.height * 64;
	game->win_ptr = mlx_new_window(game->mlx_ptr, window_width, window_heigth, "so_long");
	if (!game->win_ptr)
	{
		ft_printf("Error - Window creation failed\n");
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		game->mlx_ptr = NULL;
		return ;
	}
	game->buffer = mlx_new_image(game->mlx_ptr, window_width, window_heigth);
}

int	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		ft_printf("Error - Mlx init\n");
		return (0);
	}
	initialize_window(game);
	if (!game->win_ptr)
		return (0);
	return (1);
}

static int	load_image(void *mlx, void **img, t_game *game, char *path)
{
	int		width;
	int		height;
	char	*error_msg;

	if (ft_strcmp(path, "assets/tile.xpm") == 0)
		error_msg = "Error - floor render";
	else if (ft_strcmp(path, "assets/player.xpm") == 0)
		error_msg = "Error - player render";
	else if (ft_strcmp(path, "assets/collectible.xpm") == 0)
		error_msg = "Error - collectible render";
	else if (ft_strcmp(path, "assets/wall.xpm") == 0)
		error_msg = "Error - Wall render";
	else if (ft_strcmp(path, "assets/exit.xpm") == 0)
		error_msg  = "Error - exit render";
	*img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	if (!*img || (ft_strcmp(path, "assets/tile.xpm")
		== 0 && (height != 64 || width != 64)))
		{
			ft_printf("%s/n", error_msg);
			free_map(game->map.map, game->map.height);
			if (game->win_ptr)
				mlx_destroy_window(game->mlx_ptr, game->win_ptr);
			return (0);
		}
		return (1);
}

int	load_assets(t_game *game)
{
	if (!load_image(game->mlx_ptr, &game->img.floor, game, "assets/tile.xpm")
		|| !load_image())
}