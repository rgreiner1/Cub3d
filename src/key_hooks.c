/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreiner <rgreiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:10:04 by rgreiner          #+#    #+#             */
/*   Updated: 2024/03/12 14:58:34 by rgreiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_move(t_global *global, int move)
{
	mlx_destroy_image(global->mlx, global->minimap.ref);
	mlx_destroy_image(global->mlx, global->game.ref);
	global->minimap.ref = mlx_new_image(global->mlx, \
		(ft_longest(global) + 1) * SIZE_MAP, \
		(ft_longest_y(global) + 1) * SIZE_MAP);
	global->game.ref = mlx_new_image(global->mlx, WIDTH, HEIGHT);
	init_map(global, 0, 0);
	ft_next_move(global, move, 0.0, 0.0);
	ft_create_rays(global, global->angle_deg, -1.0, \
		tan((double)FOV / 2 * M_PI / 180));
	mlx_put_image_to_window(global->mlx, global->win, \
		global->game.ref, 0, 0);
	mlx_put_image_to_window(global->mlx, \
		global->win, global->minimap.ref, 0, 0);
}

int	ft_destroy(t_global *global)
{
	mlx_destroy_window(global->mlx, global->win);
	exit (EXIT_SUCCESS);
}

void	ft_check_key2(int keycode, t_global *global)
{
	if (keycode == 65361)
	{
		global->angle_deg -= 1;
		if (global->angle_deg < 0)
			global->angle_deg = 359;
	}
	if (keycode == 65363)
	{
		global->angle_deg += 1;
		if (global->angle_deg > 359)
			global->angle_deg = 0;
	}
	mlx_destroy_image(global->mlx, global->minimap.ref);
	mlx_destroy_image(global->mlx, global->game.ref);
	global->minimap.ref = mlx_new_image(global->mlx, \
		(ft_longest(global) + 1) * SIZE_MAP, \
		(ft_longest_y(global) + 1) * SIZE_MAP);
	global->game.ref = mlx_new_image(global->mlx, WIDTH, HEIGHT);
	init_map(global, 0, 0);
	ft_create_rays(global, global->angle_deg, -1.0, \
		tan((double)FOV / 2 * M_PI / 180));
	mlx_put_image_to_window(global->mlx, global->win, \
		global->game.ref, 0, 0);
	mlx_put_image_to_window(global->mlx, \
		global->win, global->minimap.ref, 0, 0);
}

int	ft_check_key(int keycode, t_global *global)
{
	if (keycode == 65307)
		ft_destroy(global);
	if (keycode == 119)
		ft_move(global, 1);
	if (keycode == 115)
		ft_move(global, 2);
	if (keycode == 97)
		ft_move(global, 3);
	if (keycode == 100)
		ft_move(global, 4);
	ft_check_key2(keycode, global);
	return (0);
}
