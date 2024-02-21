/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreiner <rgreiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:14:35 by rgreiner          #+#    #+#             */
/*   Updated: 2024/02/21 18:53:26 by rgreiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_angle_deg(t_global *data, char c)
{
	if (c == 'N')
		data->angle_deg = 0;
	else if (c == 'E')
		data->angle_deg = 90;
	else if (c == 'S')
		data->angle_deg = 180;
	else if (c == 'W')
		data->angle_deg = 270;
	data->ray.dist_x = 0;
	data->ray.pos_x_x = data->pos_player_x;
	data->ray.pos_x_y = data->pos_player_y;
	data->ray.dist_y = 0;
	data->ray.pos_y_x = data->pos_player_x;
	data->ray.pos_y_y = data->pos_player_y;
}

void	ft_angle_x(t_global *data)
{
	if (data->angle_deg >= 0 && data->angle_deg < 90)
		data->ray.ang_x = 90 - data->angle_deg;
	else if (data->angle_deg >= 90 && data->angle_deg < 180)
		data->ray.ang_x = data->angle_deg - 90;
	else if (data->angle_deg >= 180 && data->angle_deg < 270)
		data->ray.ang_x = 270 - data->angle_deg;
	else if (data->angle_deg >= 270 && data->angle_deg < 360)
		data->ray.ang_x = data->angle_deg - 270;
	if (data->angle_deg >= 0 && data->angle_deg < 180)
		data->ray.side_x_x = ceil(data->ray.pos_x_x) - data->ray.pos_x_x;
	else if (data->angle_deg >= 180 && data->angle_deg < 360)
		data->ray.side_x_x = data->ray.pos_x_x - floor(data->ray.pos_x_x);
}

void	ft_angle_y(t_global *data, double angle_rad)
{
	if ((data->angle_deg >= 0 && data->angle_deg < 90) || \
		(data->angle_deg >= 270 && data->angle_deg < 360))
		data->ray.side_y_y = data->ray.pos_y_y - floor(data->ray.pos_y_y);
	else if (data->angle_deg >= 90 && data->angle_deg < 270)
		data->ray.side_y_y = (ceil(data->ray.pos_y_y) - data->ray.pos_y_y);
	data->ray.side_y = data->ray.side_y_y / cos(angle_rad);
	data->ray.side_y_x = data->ray.side_y * sin(angle_rad);
	data->ray.dist_y += data->ray.side_y;
	if (data->angle_deg >= 0 && data->angle_deg < 180)
		data->ray.pos_y_x += data->ray.side_y_x;
	else
		data->ray.pos_y_x -= data->ray.side_y_x;
}

void	ft_search_side_x(t_global *data)
{
	double	angle_rad;

	ft_angle_x(data);
	angle_rad = (data->ray.ang_x * M_PI) / 180;
	data->ray.side_x = data->ray.side_x_x / cos(angle_rad);
	data->ray.side_x_y = data->ray.side_x * sin(angle_rad);
	data->ray.dist_x += data->ray.side_x;
	if (data->angle_deg >= 0 && data->angle_deg < 180)
		data->ray.pos_x_x += data->ray.side_x_x;
	else
		data->ray.pos_x_x -= data->ray.side_x_x;
	if ((data->angle_deg >= 0 && data->angle_deg < 90) || \
		(data->angle_deg >= 270 && data->angle_deg < 360))
		data->ray.pos_x_y -= data->ray.side_x_y;
	else
		data->ray.pos_x_y += data->ray.side_x_y;
}

void	ft_search_side_y(t_global *data)
{
	double	angle_rad;

	if (data->angle_deg >= 0 && data->angle_deg < 90)
		data->ray.ang_y = data->angle_deg;
	else if (data->angle_deg >= 90 && data->angle_deg < 180)
		data->ray.ang_y = 180 - data->angle_deg;
	else if (data->angle_deg >= 180 && data->angle_deg < 270)
		data->ray.ang_y = data->angle_deg - 180;
	else if (data->angle_deg >= 270 && data->angle_deg < 360)
		data->ray.ang_y = 360 - data->angle_deg;
	angle_rad = (data->ray.ang_y * M_PI) / 180;
	ft_angle_y(data, angle_rad);
	if ((data->angle_deg >= 0 && data->angle_deg < 90) || \
		(data->angle_deg >= 270 && data->angle_deg < 360))
		data->ray.pos_y_y -= data->ray.side_y_y;
	else
		data->ray.pos_y_y += data->ray.side_y_y;
}
