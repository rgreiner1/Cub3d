/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_delta.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <ogregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:29:20 by rgreiner          #+#    #+#             */
/*   Updated: 2024/03/04 11:53:32 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_angle_delta_x(t_global *data)
{
	if (data->angle_deg >= 0.0 && data->angle_deg < 90.0)
		data->ray.ang_x = 90.0 - data->angle_deg;
	else if (data->angle_deg >= 90.0 && data->angle_deg < 180.0)
		data->ray.ang_x = data->angle_deg - 90.0;
	else if (data->angle_deg >= 180.0 && data->angle_deg < 270.0)
		data->ray.ang_x = 270.0 - data->angle_deg;
	else if (data->angle_deg >= 270.0 && data->angle_deg < 360.0)
		data->ray.ang_x = data->angle_deg - 270.0;
	data->ray.side_x_x = 1.0;
}

void	ft_angle_delta_y(t_global *data, double angle_rad)
{
	data->ray.side_y_y = 1.0;
	data->ray.side_y = data->ray.side_y_y / cos(angle_rad);
	data->ray.side_y_x = data->ray.side_y * sin(angle_rad);
	data->ray.dist_y += data->ray.side_y;
	if (data->angle_deg >= 0.0 && data->angle_deg < 180.0)
		data->ray.pos_y_x += data->ray.side_y_x;
	else
		data->ray.pos_y_x -= data->ray.side_y_x;
}

void	ft_delta_x(t_global *data)
{
	double	angle_rad;

	ft_angle_delta_x(data);
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

void	ft_delta_y(t_global *data)
{
	double	angle_rad;

	if (data->angle_deg >= 0.0 && data->angle_deg < 90.0)
		data->ray.ang_y = data->angle_deg;
	else if (data->angle_deg >= 90.0 && data->angle_deg < 180.0)
		data->ray.ang_y = 180.0 - data->angle_deg;
	else if (data->angle_deg >= 180.0 && data->angle_deg < 270.0)
		data->ray.ang_y = data->angle_deg - 180.0;
	else if (data->angle_deg >= 270.0 && data->angle_deg < 360.0)
		data->ray.ang_y = 360.0 - data->angle_deg;
	angle_rad = (data->ray.ang_y * M_PI) / 180.0;
	ft_angle_delta_y(data, angle_rad);
	if ((data->angle_deg >= 0.0 && data->angle_deg < 90.0) || \
		(data->angle_deg >= 270.0 && data->angle_deg < 360.0))
		data->ray.pos_y_y -= data->ray.side_y_y;
	else
		data->ray.pos_y_y += data->ray.side_y_y;
	data->ray.opp_total_y += data->ray.side_y;
}

void	init_ray(t_global *data)
{
	data->ray.dist_x = 0.0;
	data->ray.opp_total_x = 0.0;
	data->ray.pos_x_x = data->pos_player_x;
	data->ray.pos_x_y = data->pos_player_y;
	data->ray.dist_y = 0.0;
	data->ray.opp_total_y = 0.0;
	data->ray.pos_y_x = data->pos_player_x;
	data->ray.pos_y_y = data->pos_player_y;
}
