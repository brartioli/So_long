/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:38:12 by bfernan2          #+#    #+#             */
/*   Updated: 2025/12/02 17:42:58 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	args_are_valid(int argc, char **argv, int *fd)
{
	if (argc != 2)
	{
		ft_printf("Error - no Map\n");
		return (0);
	}
	*fd = open(argv[1], O_RDONLY);
	if (*fd < 0)
	{
		ft_printf("Error - invalid map\n");
		return (0);
	}
	return (1);
}

void	count_collectibles(t_game *game, int *count_collectibles)
{
	int	x;
	int	y;

	*count_collectibles = 0;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'C')
				(*count_collectibles)++;
			x++;
		}
		y++;
	}
}

void	free_map(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_game(t_game *game)
{
	if (game->map.map)
		free_map(game->map.map, game->map.height);
}

int	add_map_line(t_game *game, char *line)
{
	char	*newline;

	if (!line)
		return (0);
	if (game->map.height >= 100)
	{
		ft_printf("Error - map too big\n");
		free(line);
		return (0);
	}
	newline = ft_strchr(line, '\n');
	if (newline)
		*newline = '\0';
	game->map.map[game->map.height] = ft_strdup(line);
	if (!game->map.map[game->map.height])
		return (ft_printf("Error - Memory allocation\n"), 0);
	game->map.height++;
	return (1);
}
