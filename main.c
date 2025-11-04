/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:02:26 by bfernan2          #+#    #+#             */
/*   Updated: 2025/11/03 21:24:47 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	callback(int key, void *mlx_ref);

int main(void)
{
	void	*mlx_ref;
	void	*window_ref;
	
	mlx_ref = mlx_init();
	window_ref = mlx_new_window(mlx_ref, 500, 500, "teste");
	mlx_hook(window_ref, 17, 0L, mlx_loop_end, mlx_ref);
	mlx_hook(window_ref, 3, 1L << 1, callback, mlx_ref);
	mlx_loop(mlx_ref);
}

int	callback(int key, void *mlx_ref)
{
	if (key == 65307)
		mlx_loop_end(mlx_ref);
	return (1);
}