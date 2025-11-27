/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:17:22 by bfernan2          #+#    #+#             */
/*   Updated: 2025/11/26 18:08:53 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	read_map(t_game *game, int fd)
{
	char	*line;

	game->map.map = malloc(sizeof(char *) * 101);
	if (!game->map.map)
	{
		ft_printf("Error - Memory failed\n");
		return (0);
	}
	game->map.height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!add_map_line(game, line))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	game->map.map[game->map.height] = NULL;
	close (fd);
	return (1);
}

int	validate_map(t_game *game)
{
	if (!validate_collectibles(game) || !validate_rectangle(game))
	{
		free_map(game->map.map, game->map.height);
		return (0);
	}
	return (1);
}
