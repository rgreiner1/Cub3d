/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreiner <rgreiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:54:30 by rgreiner          #+#    #+#             */
/*   Updated: 2024/03/07 13:51:05 by rgreiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	create_wall_floor(t_global *global, int i, int j, int color)
{
	int	count;
	int	draw;
	int	l;
	int	z;

	count = SIZE_MAP * i;
	l = 0;
	while (l <= SIZE_MAP)
	{
		draw = SIZE_MAP * j;
		z = 0;
		while (z <= SIZE_MAP)
		{
			my_mlx_pixel_put(global, draw, count, color);
			draw++;
			z++;
		}
		l++;
		count++;
	}
}

void	create_object(t_global *global, int color)
{
	double	count;
	double	draw;
	int		l;
	int		z;

	count = global->pos_player_y * SIZE_MAP - 2;
	l = 0;
	while (l <= 4)
	{
		draw = global->pos_player_x * SIZE_MAP - 2;
		z = 0;
		while (z <= 4)
		{
			my_mlx_pixel_put(global, draw, count, color);
			draw++;
			z++;
		}
		l++;
		count++;
	}
}

void	init_map(t_global *global, int i, int j)
{
	while (global->map[i])
	{
		j = 0;
		while (global->map[i][j])
		{
			if (global->map[i][j] != 32 && global->map[i][j] != '\n')
				create_wall_floor(global, i, j, 0xffffff);
			if (global->map[i][j] == '1')
				create_wall_floor(global, i, j, 0x3c00ff);
			j++;
		}
		i++;
	}
	create_object(global, 0x05f515);
}

void	init_player_pos(t_global *global)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (global->map[i])
	{
		j = 0;
		while (global->map[i][j])
		{
			if (global->map[i][j] == 'N' || global->map[i][j] == 'W' \
				|| global->map[i][j] == 'E' || global->map[i][j] == 'S')
			{
				global->pos_player_x = j + 0.5;
				global->pos_player_y = i + 0.5;
				check_angle_deg(global, global->map[i][j]);
			}
			j++;
		}
		i++;
	}
}

int	ft_longest_y(t_global *global)
{
	int	len;

	len = 0;
	while (global->map[len])
		len++;
	return (len);
}

void	ft_minimap(t_global *global)
{
	ft_init_mlx(global);
	global->minimap.ref = mlx_new_image(global->mlx, \
		(ft_longest(global) + 1) * SIZE_MAP, \
			(ft_longest_y(global) + 1) * SIZE_MAP);
	global->minimap.addr = mlx_get_data_addr(global->minimap.ref, \
		&global->minimap.bits_per_pixel, &global->minimap.line_length, \
			&global->minimap.endian);
	global->game.ref = mlx_new_image(global->mlx, WIDTH, HEIGHT);
	global->game.addr = mlx_get_data_addr(global->game.ref, \
		&global->game.bits_per_pixel, &global->game.line_length, \
			&global->game.endian);
	init_player_pos(global);
	init_map(global, 0, 0);
	ft_create_rays(global);
	mlx_put_image_to_window(global->mlx, global->win, \
		global->game.ref, 0, 0);
	mlx_put_image_to_window(global->mlx, global->win, \
		global->minimap.ref, 0, 0);
	save_picture(global);
	mlx_hook(global->win, 2, 1L<<0, ft_check_key, global);
	mlx_hook(global->win, 17, 0, ft_destroy, global);
	mlx_loop(global->mlx);
}
