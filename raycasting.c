/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <ogregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:14:35 by rgreiner          #+#    #+#             */
/*   Updated: 2024/02/19 20:08:04 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
void    ft_create_ray(t_global *global, int color)
{
  
	
	
}*/

void    check_angle_deg(t_global *data, char c)
{
	if(c == 'N')
		data->angle_deg = 0;
	else if(c == 'E')
		data->angle_deg = 90;
	else if (c == 'S')
		data->angle_deg = 180;
	else if(c == 'W')
		data->angle_deg = 270;
}

void    ft_search_side_x(t_global *data)
{
	double	angle_rad;
	data->ray.dist_x = 0;
	data->ray.pos_x_x = data->pos_player_x;
	data->ray.pos_x_y = data->pos_player_y;
	
	if(data->angle_deg >= 0 && data->angle_deg < 90)
		data->ray.ang_x = 90 - data->angle_deg;
	else if(data->angle_deg >= 90 && data->angle_deg < 180)
		data->ray.ang_x = data->angle_deg - 90;
	else if(data->angle_deg >= 180 && data->angle_deg < 270)
		data->ray.ang_x = 270 - data->angle_deg;
	else if(data->angle_deg >= 270 && data->angle_deg < 360)
		data->ray.ang_x = data->angle_deg - 270;
	if((data->angle_deg >= 0 && data->angle_deg < 90) || (data->angle_deg >= 270 && data->angle_deg < 360))
		data->ray.side_x_y = (ceil(data->ray.pos_x_x) - data->ray.pos_x_x);
	else if(data->angle_deg >= 90 && data->angle_deg < 270)
		data->ray.side_x_y = (floor(data->ray.pos_x_x) - data->ray.pos_x_x);
	angle_rad = (data->ray.side_x_y * M_PI) / 180;
	if (angle_rad == 0)
		angle_rad = 1;
	data->ray.side_x = data->ray.side_x_y / cos(angle_rad);
	data->ray.side_x_x = data->ray.side_x * sin(angle_rad);
	data->ray.dist_x += data->ray.side_x;
	data->ray.pos_x_x += data->ray.side_x_x;
	data->ray.pos_x_y += data->ray.side_x_y;
	my_mlx_pixel_put(data, data->ray.pos_x_x * 8, data->ray.pos_x_y * 8, 0xFF0000);
	printf("dist_x %f\n pos_x_x %f\n pos_x_y %f\n", data->ray.dist_x, data->ray.pos_x_x, data->ray.pos_x_y);
}

void    ft_search_side_y(t_global *data)
{
	double	angle_rad;
	
	data->ray.dist_y = 0;
	data->ray.pos_y_x = data->pos_player_x;
	data->ray.pos_y_y = data->pos_player_y;
	if(data->angle_deg >= 0 && data->angle_deg < 90)
		data->ray.ang_y = data->angle_deg;
	else if(data->angle_deg >= 90 && data->angle_deg < 180)
		data->ray.ang_y = 180 - data->angle_deg;
	else if(data->angle_deg >= 180 && data->angle_deg < 270)
		data->ray.ang_y = data->angle_deg - 180;
	else if(data->angle_deg >= 270 && data->angle_deg < 360)
		data->ray.ang_y = 360 - data->angle_deg;
	if((data->angle_deg >= 0 && data->angle_deg < 90) || (data->angle_deg >= 270 && data->angle_deg < 360))
		data->ray.side_y_y = (ceil(data->ray.pos_y_x) - data->ray.pos_y_x);
	else if(data->angle_deg >= 90 && data->angle_deg < 270)
		data->ray.side_y_y = (floor(data->ray.pos_y_x) - data->ray.pos_y_x);
	angle_rad = (data->ray.side_y_y * M_PI) / 180;
	if (angle_rad == 0)
		angle_rad = 1;
	//printf("side_y %d\n", data->ray.ang_y);
	data->ray.side_y = data->ray.side_y_y / cos(angle_rad);
	data->ray.side_y_x = data->ray.side_y * sin(angle_rad);
	data->ray.dist_y += data->ray.side_y;
	data->ray.pos_y_x += data->ray.side_y_x;
	data->ray.pos_y_y += data->ray.side_y_y;
	//printf("dist_y %f\n pos_y_y %f\n pos_y_x %f\n", data->ray.dist_y, data->ray.pos_y_y, data->ray.pos_y_x);
	//printf("side_y %f\n side_y_y %f\n side_y_x %f\n", data->ray.side_y, data->ray.side_y_y, data->ray.side_y_x);
	my_mlx_pixel_put(data, data->ray.pos_y_x * 8, data->ray.pos_y_y * 8, 0x582900);
}
