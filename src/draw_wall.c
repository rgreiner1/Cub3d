/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreiner <rgreiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:37:34 by rgreiner          #+#    #+#             */
/*   Updated: 2024/03/11 18:44:21 by rgreiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_draw_wall(t_global *global, int i)
{
	double	tmp_dist;
	int		line;

	if (global->ray.dist_x < global->ray.dist_y)
	{
		tmp_dist = global->ray.dist_x * \
			cos((global->cpy_angle_deg - global->angle_deg) * M_PI / 180);
	}
	else
	{
		tmp_dist = global->ray.dist_y * \
			cos((global->cpy_angle_deg - global->angle_deg) * M_PI / 180);
	}
	line = (int)HEIGHT / tmp_dist;
	global->drawstart = -line / 2.0 + HEIGHT / 2.0;
	if (global->drawstart < 0)
		global->drawstart = 0;
	global->drawend = line / 2.0 + HEIGHT / 2.0;
	ft_text(global, i, correct_text(global), \
	global->drawend - global->drawstart);
}

void	my_mlx_pixel_put(t_global *global, int x, int y, int color)
{
	char	*dst;

	dst = global->minimap.addr + \
		(y * global->minimap.line_length + x * \
			(global->minimap.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_pixel_put2(t_global *global, int x, int y, int color)
{
	char	*dst;

	dst = global->game.addr + \
		(y * global->game.line_length + x * (global->game.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
