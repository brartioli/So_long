/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:17:22 by bfernan2          #+#    #+#             */
/*   Updated: 2025/11/13 20:17:58 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	read_map(t_game *game, int fd)
{
	char	*line;
	int		i;

	game->map.map = malloc(sizeof(char *) * 101);
	if (!game->map.map)
		return (ft_printf("Error\nMemory allocation failed\n"), 0);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL && i < 100)
	{
		game->map.map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	game->map.map[i] = NULL;
	game->map.height = i;
	if (i > 0)
		game->map.width = ft_strlen(game->map.map[0]);
	return (1);
}

int	validate_map()
{
	
}