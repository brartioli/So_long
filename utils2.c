/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmfanfa <tmfanfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:23:28 by bfernan2          #+#    #+#             */
/*   Updated: 2025/11/30 17:28:22 by tmfanfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	find_player_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

char	**creat_map_copy(t_game *game)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (game->map.height + 1));
	if (!copy)
		return (NULL);
	 i = 0;
	 while (i < game->map.height)
	 {
		copy[i] = ft_strdup(game->map.map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	 }
	 copy[i] = NULL;
	 return (copy);
}

void	find_player(t_game *game, int *player_count)
{
	int	x;
	int	y;

	*player_count = 0;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'P')
			{
				(*player_count)++;
				game->player.x = x;
				game->player.y = y;
			}
			x++;
		}
		y++;
	}
}

int	check_vertical_walls(t_game *game, int width)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		/*if (i < game->map.height)
			return (ft_printf("Error - Map has NULL line\n"), 0);*/
		if (game->map.map[i][0] != '1' || game->map.map[i][width - 1] != '1')
		{
			ft_printf("Error - Map incomplete. Vertical walls!\n");
			return (0);
		}
		i++;
	}
	return (1);
}
