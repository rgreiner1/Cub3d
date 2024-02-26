/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreiner <rgreiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:10:04 by rgreiner          #+#    #+#             */
/*   Updated: 2024/02/26 14:41:42 by rgreiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move(t_global *global, int move)
{
	printf("%d\n", move);
	if (move == 1 && global->map[(int)floor(global->pos_player_x)] \
		[(int)ceil(global->pos_player_y)] != '1')
		global->pos_player_y -= 0.1;
	if (move == 2 && global->map[(int)floor(global->pos_player_x)] \
		[(int)floor(global->pos_player_y)] != '1')
		global->pos_player_y += 0.1;
	if (move == 3 && global->map[(int)floor(global->pos_player_x - 0.1)] \
		[(int)floor(global->pos_player_y)] != '1')
		global->pos_player_x -= 0.1;
	if (move == 4 && global->map[(int)floor(global->pos_player_x + 0.1)] \
		[(int)floor(global->pos_player_y)] != '1')
		global->pos_player_x += 0.1;
	mlx_destroy_image(global->img.mlx, global->img.img);
	global->img.img = mlx_new_image(global->img.mlx, (global->data.axes_x + 1) * 64, \
		(global->data.axes_y + 1) * 64);
	init_map(global, 0, 0);
	ft_create_rays(global);
	mlx_put_image_to_window(global->img.mlx, \
		global->img.win, global->img.img, 0, 0);
}

int	ft_destroy(t_global *global)
{
	mlx_destroy_window(global->img.mlx, global->img.win);
	//free global
	exit (EXIT_SUCCESS);
}

void	ft_check_key2(int keycode, t_global *global)
{
	if (keycode == 65361)
	{
		global->angle_deg += 1;
		if (global->angle_deg > 359)
			global->angle_deg = 0;
		printf("Deplacement camera gauche\n");
	}
	if (keycode == 65363)
	{
		global->angle_deg -= 1;
		if (global->angle_deg < 0)
			global->angle_deg = 359;
		printf("Deplacement camera droite\n");
	}
	mlx_destroy_image(global->img.mlx, global->img.img);
	global->img.img = mlx_new_image(global->img.mlx, (global->data.axes_x + 1) * 64, \
		(global->data.axes_y + 1) * 64);
	init_map(global, 0, 0);
	ft_create_rays(global);
	mlx_put_image_to_window(global->img.mlx, \
		global->img.win, global->img.img, 0, 0);
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
