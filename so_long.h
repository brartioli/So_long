/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:02:13 by bfernan2          #+#    #+#             */
/*   Updated: 2025/11/29 15:19:44 by bfernan2         ###   ########.fr       */
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
void	find_player_position(t_game *game);
int		exit_game(t_game *game);
void	get_new_position(int keycode, int *new_x, int *new_y, t_game *game);
int		key_hook(int keycode, t_game *game);
int		is_valid_move(int new_x, int new_y, t_game *game);
//validations
int		validate_collectibles(t_game *game);
int		validate_rectangle(t_game *game);
int		validate_walls(t_game *game);
int		validate_player(t_game *game);
int		validate_path(t_game *game);
int		validate_exit(t_game *game);
int		validate_map_characters(char **map);
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
void	find_player(t_game *game, int *player_count);
int		check_vertical_walls(t_game *game, int width);
int		check_horizontal_walls(t_game *game, int width);
int		check_reachable_items(char **map_copy, t_game *game);
void	free_map_copy(char **map_copy, int heigth);
//render
void	render(t_game *game);
char	**creat_map_copy(t_game *game);
void	render_tile(t_game *game, int x, int y, char tile_type);
void	render_tile_at_position(t_game *game, char **map_copy, int x, int y);
void	update_player_tile_and_sync(t_game *game);
//handlers_functions
void	handle_collectible(t_game *game);
int		handle_exit(t_game *game);
//flood_fill
void	flood_fill(char **map, int x, int y, int height);
int		is_valid_position(char **map, int x, int y, int heigth);
//hook
int		key_hook(int keycode, t_game *game);

#endif