/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreiner <rgreiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:15:27 by rgreiner          #+#    #+#             */
/*   Updated: 2024/03/12 15:18:30 by rgreiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_create_rays1(t_global *global, double tmp, double opp)
{
	global->cpy_angle_deg = tmp;
	global->diff_opp = opp / (WIDTH / 2);
	global->alpha = atan(opp) / M_PI * 180;
	global->angle_deg -= global->alpha;
	if (global->angle_deg < 0.0)
		global->angle_deg = 360.0 + global->angle_deg;
	ft_create_f_s(global);
}

int	ft_create_rays2(t_global *global)
{
	if (global->angle_deg >= 0.0 && global->angle_deg <= 180.0)
	{
		if (global->map[(int)global->ray.pos_x_y] \
			[(int)global->ray.pos_x_x] == '1')
		{
			my_mlx_pixel_put(global, \
				global->ray.pos_x_x * SIZE_MAP, \
				global->ray.pos_x_y * SIZE_MAP, 0xFF0000);
			return (1);
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
			return (1);
		}
		ft_delta_x(global);
	}
	return (0);
}

int	ft_create_rays3(t_global *global)
{
	if (global->angle_deg >= 90.0 && global->angle_deg <= 270.0)
	{
		if (global->map[(int)global->ray.pos_y_y] \
			[(int)global->ray.pos_y_x] == '1')
		{
			my_mlx_pixel_put(global, \
				global->ray.pos_y_x * SIZE_MAP, \
				global->ray.pos_y_y * SIZE_MAP, 0xFF0000);
			return (1);
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
			return (1);
		}
		ft_delta_y(global);
	}
	return (0);
}

void	ft_create_rays(t_global *global, double tmp, double i, double opp)
{
	ft_create_rays1(global, tmp, opp);
	while (++i <= WIDTH)
	{
		ft_create_rays6(global);
		while (1)
		{
			if (global->ray.dist_x < global->ray.dist_y)
			{
				if (ft_create_rays2(global) == 1)
					break ;
			}
			else
			{
				if (ft_create_rays3(global) == 1)
					break ;
			}
		}
		ft_draw_wall(global, i);
		if (i <= WIDTH / 2)
			opp -= ft_create_rays4(global, tmp, opp);
		else
			opp += ft_create_rays5(global, tmp, opp);
		ft_create_rays7(global);
	}
	global->angle_deg = tmp;
}
