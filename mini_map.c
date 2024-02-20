/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreiner <rgreiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:54:30 by rgreiner          #+#    #+#             */
/*   Updated: 2024/02/20 13:36:36 by rgreiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

void	my_mlx_pixel_put(t_global *global, int x, int y, int color)
{
	char	*dst;

	dst = global->img.addr + (y * global->img.line_length + x * (global->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	create_wall_floor(t_global *global, int i, int j, int color)
{
	int	count;
	int	draw;
	int	l;
	int	z;

	count = SIZE_MAP * i;
	l = 0;
	while(l <= SIZE_MAP)
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
	int	l;
	int	z;

	count = global->pos_player_x * SIZE_MAP - 2;
	l = 0;
	while(l <= 4)
	{
		draw = global->pos_player_y * SIZE_MAP - 2;
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

void    init_map(t_global *global, int i, int j)
{
    while(global->map[i])
    {
        j = 0;
        while(global->map[i][j])
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
	while(global->map[i])
    {
        j = 0;
        while(global->map[i][j])
            {
				if (global->map[i][j] == 'N' || global->map[i][j] == 'W' || global->map[i][j] == 'E' || global->map[i][j] == 'S')
					{
						check_angle_deg(global, global->map[i][j]);
						global->pos_player_x = i + 0.5;
						global->pos_player_y = j + 0.5;
					}
				j++;
            }
        i++;
    }
}

void    ft_minimap(t_global *global)
{   
	global->img.mlx = mlx_init();
	global->img.win = mlx_new_window(global->img.mlx, 640, 480, "cub3d");
	global->img.img = mlx_new_image(global->img.mlx, global->data.axes_x * 64, global->data.axes_y * 64);
    global->img.addr = mlx_get_data_addr(global->img.img, &global->img.bits_per_pixel, &global->img.line_length, &global->img.endian);
	//printf("bits per pixels = %d\n", global->img.bits_per_pixel);
	//printf("line_length = %d\n", global->img.line_length);
	//printf("endian = %d\n", global->img.endian);
	init_player_pos(global);
    init_map(global, 0, 0);
	ft_search_side_x(global);
	ft_search_side_y(global);
	mlx_put_image_to_window(global->img.mlx, global->img.win, global->img.img, 0, 0);
    mlx_key_hook(global->img.win, ft_check_key, global);
	mlx_hook(global->img.win, 17, 0, ft_destroy, global);
	mlx_loop(global->img.mlx);
}