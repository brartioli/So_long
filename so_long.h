/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:02:13 by bfernan2          #+#    #+#             */
/*   Updated: 2025/11/13 20:47:23 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>

# define TITLE_SIZE 64

typedef struct  s_map
{
	char	**map;
	int		width;
	int		height;
	int		player_count;
	int		collectibles;
	int		exit_count;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	moves;
}	t_player;

typedef struct s_image
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
	
}	t_image;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_player	player;
	t_image		img;
	int			collected;
}	t_game;

int		args_are_valid(int argc, char **argv, int *fd);
int		read_map(t_game *game, int fd);
char	*get_next_line(int fd);
void	init_game(t_game *game);

#endif