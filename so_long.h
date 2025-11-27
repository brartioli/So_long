/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:02:13 by bfernan2          #+#    #+#             */
/*   Updated: 2025/11/26 20:54:05 by bfernan2         ###   ########.fr       */
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

typedef struct s_map
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
	void		*buffer;
	t_map		map;
	t_player	player;
	t_image		img;
	int			collected;
}	t_game;

//map functions
int		read_map(t_game *game, int fd);
int		validate_map(t_game *game);
char	*get_next_line(int fd);
//game functions
void	init_game(t_game *game);
void	setup_game(t_game *game);
void	setup_game(t_game *game);
int		validate_collectibles(t_game *game);
int		validate_rectangle(t_game *game);
void	find_player_position(t_game *game);
int		exit_game(t_game *game);
void	get_new_position(int keycode, int *new_x, int *new_y, t_game *game);
int		key_hook(int keycode, t_game *game);
int		is_valid_move(int new_x, int new_y, t_game *game);
//mlx function
int		init_mlx(t_game *game);
void	initialize_window(t_game *game);
int		load_assets(t_game *game);
int		error_msg(char *msg);
//Utils functions
int		ft_strcmp(const char *s1, const char *s2);
int		args_are_valid(int argc, char **argv, int *fd);
void	count_collectibles(t_game *game, int *count_collectibles);
void	free_map(char **map, int height);
void	free_game(t_game *game);
int		add_map_line(t_game *game, char *line);
//render
void	render(t_game *game);
char	**creat_map_copy(t_game *game);

#endif