/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <ogregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:14:35 by rgreiner          #+#    #+#             */
/*   Updated: 2024/03/04 11:54:05 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_angle_deg(t_global *data, char c)
{
	if (c == 'N')
		data->angle_deg = 0.0;
	else if (c == 'E')
		data->angle_deg = 90.0;
	else if (c == 'S')
		data->angle_deg = 180.0;
	else if (c == 'W')
		data->angle_deg = 270.0;
}

void	ft_angle_x(t_global *data)
{
	if (data->angle_deg >= 0.0 && data->angle_deg < 90.0)
		data->ray.ang_x = 90.0 - data->angle_deg;
	else if (data->angle_deg >= 90.0 && data->angle_deg < 180.0)
		data->ray.ang_x = data->angle_deg - 90.0;
	else if (data->angle_deg >= 180.0 && data->angle_deg < 270.0)
		data->ray.ang_x = 270.0 - data->angle_deg;
	else if (data->angle_deg >= 270.0 && data->angle_deg < 360.0)
		data->ray.ang_x = data->angle_deg - 270.0;
	if (data->angle_deg >= 0.0 && data->angle_deg < 180.0)
		data->ray.side_x_x = ceil(data->ray.pos_x_x) - data->ray.pos_x_x;
	else if (data->angle_deg >= 180.0 && data->angle_deg < 360.0)
		data->ray.side_x_x = data->ray.pos_x_x - floor(data->ray.pos_x_x);
}

void	ft_angle_y(t_global *data, double angle_rad)
{
	if ((data->angle_deg >= 0.0 && data->angle_deg < 90.0) || \
		(data->angle_deg >= 270.0 && data->angle_deg < 360.0))
		data->ray.side_y_y = data->ray.pos_y_y - floor(data->ray.pos_y_y);
	else if (data->angle_deg >= 90.0 && data->angle_deg < 270.0)
		data->ray.side_y_y = (ceil(data->ray.pos_y_y) - data->ray.pos_y_y);
	data->ray.side_y = data->ray.side_y_y / cos(angle_rad);
	data->ray.side_y_x = data->ray.side_y * sin(angle_rad);
	data->ray.dist_y += data->ray.side_y;
	if (data->angle_deg >= 0.0 && data->angle_deg < 180.0)
		data->ray.pos_y_x += data->ray.side_y_x;
	else
		data->ray.pos_y_x -= data->ray.side_y_x;
}

void	ft_search_side_x(t_global *data)
{
	double	angle_rad;

	ft_angle_x(data);
	angle_rad = (data->ray.ang_x * M_PI) / 180.0;
	data->ray.side_x = data->ray.side_x_x / cos(angle_rad);
	data->ray.side_x_y = data->ray.side_x * sin(angle_rad);
	data->ray.dist_x += data->ray.side_x;
	if (data->angle_deg >= 0.0 && data->angle_deg < 180.0)
		data->ray.pos_x_x += data->ray.side_x_x;
	else
		data->ray.pos_x_x -= data->ray.side_x_x;
	if ((data->angle_deg >= 0.0 && data->angle_deg < 90.0) || \
		(data->angle_deg >= 270.0 && data->angle_deg < 360.0))
		data->ray.pos_x_y -= data->ray.side_x_y;
	else
		data->ray.pos_x_y += data->ray.side_x_y;
	data->ray.opp_total_x += data->ray.side_x;
}

void	ft_search_side_y(t_global *data)
{
	double	angle_rad;

	if (data->angle_deg >= 0.0 && data->angle_deg < 90.0)
		data->ray.ang_y = data->angle_deg;
	else if (data->angle_deg >= 90.0 && data->angle_deg < 180.0)
		data->ray.ang_y = 180 - data->angle_deg;
	else if (data->angle_deg >= 180.0 && data->angle_deg < 270.0)
		data->ray.ang_y = data->angle_deg - 180.0;
	else if (data->angle_deg >= 270.0 && data->angle_deg < 360.0)
		data->ray.ang_y = 360.0 - data->angle_deg;
	angle_rad = (data->ray.ang_y * M_PI) / 180.0;
	ft_angle_y(data, angle_rad);
	if ((data->angle_deg >= 0.0 && data->angle_deg < 90.0) || \
		(data->angle_deg >= 270.0 && data->angle_deg < 360.0))
		data->ray.pos_y_y -= data->ray.side_y_y;
	else
		data->ray.pos_y_y += data->ray.side_y_y;
	data->ray.opp_total_y += data->ray.side_y;
}

void	ft_create_rays(t_global *global)
{
	double	i;
	double	tmp;

	i = 0.0;
	tmp = global->angle_deg;
	global->angle_deg -= FOV / 2.0;
	if (global->angle_deg < 0.0)
		global->angle_deg = 360.0 + global->angle_deg;
	ft_create_f_s(global);
	while (i <= WIDTH)
	{
		init_ray(global);
		ft_search_side_x(global);
		ft_search_side_y(global);
		while (1)
		{
			if (global->ray.dist_x == global->ray.dist_y)
				printf("%f\n", global->angle_deg);
			if (global->ray.dist_x < global->ray.dist_y)
			{
				if (global->angle_deg >= 0.0 && global->angle_deg <= 180.0)
				{
					if (global->map[(int)global->ray.pos_x_y] \
						[(int)global->ray.pos_x_x] == '1')
					{
						my_mlx_pixel_put(global, \
							global->ray.pos_x_x * SIZE_MAP, \
								global->ray.pos_x_y * SIZE_MAP, 0xFF0000);
						break ;
					}
					ft_delta_x(global);
				}
				else
				{
					if (global->map[(int)global->ray.pos_x_y] \
						[(int)global->ray.pos_x_x - 1] == '1')
					{
						my_mlx_pixel_put(global, \
							global->ray.pos_x_x * SIZE_MAP, \
								global->ray.pos_x_y * SIZE_MAP, 0xFF0000);
						break ;
					}
					ft_delta_x(global);
				}
			}
			else
			{
				if (global->angle_deg >= 90.0 && global->angle_deg <= 270.0)
				{
					if (global->map[(int)global->ray.pos_y_y] \
						[(int)global->ray.pos_y_x] == '1')
					{
						my_mlx_pixel_put(global, \
							global->ray.pos_y_x * SIZE_MAP, \
								global->ray.pos_y_y * SIZE_MAP, 0xFF0000);
						break ;
					}
					ft_delta_y(global);
				}
				else
				{
					if (global->map[(int)global->ray.pos_y_y - 1] \
						[(int)global->ray.pos_y_x] == '1')
					{
						my_mlx_pixel_put(global, \
							global->ray.pos_y_x * SIZE_MAP, \
								global->ray.pos_y_y * SIZE_MAP, 0xFF0000);
						break ;
					}
					ft_delta_y(global);
				}
			}
		}
		ft_draw_wall(global, i);
		global->angle_deg += FOV / WIDTH;
		if (global->angle_deg >= 360.0)
			global->angle_deg = 0.0;
		i++;
	}
	global->angle_deg = tmp;
}
