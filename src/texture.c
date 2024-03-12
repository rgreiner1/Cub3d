/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreiner <rgreiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:33:47 by ogregoir          #+#    #+#             */
/*   Updated: 2024/03/12 14:34:31 by rgreiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_img	*correct_text(t_global *global)
{
	if (global->ray.dist_x < global->ray.dist_y && \
		(global->angle_deg > 180 && global->angle_deg < 360))
		return (global->data.wall_o);
	else if (global->ray.dist_x > global->ray.dist_y && \
		(global->angle_deg > 90 && global->angle_deg < 270))
		return (global->data.wall_s);
	else if (global->ray.dist_x < global->ray.dist_y && \
		(global->angle_deg < 180 && global->angle_deg > 0))
		return (global->data.wall_e);
	else
		return (global->data.wall_n);
}

int	ft_color_texture(t_global *global, t_img *texture)
{
	double	wallx;
	int		texx;

	if (global->ray.dist_x < global->ray.dist_y)
		wallx = global->ray.pos_x_y - floor(global->ray.pos_x_y);
	else
		wallx = global->ray.pos_y_x - floor(global->ray.pos_y_x);
	texx = wallx * texture->width;
	if (global->ray.dist_x < global->ray.dist_y && \
		(global->angle_deg > 180 && global->angle_deg < 360))
		texx = texture->width - texx - 1;
	if (global->ray.dist_x > global->ray.dist_y && \
		(global->angle_deg > 90 && global->angle_deg < 270))
		texx = texture->width - texx - 1;
	return (texx);
}

void	ft_text(t_global *global, int i, t_img *texture, int lineh)
{
	global->step = 1.0 * texture->height / lineh;
	global->postart = (global->dstart - HEIGHT / 2 + lineh / 2) * global->step;
	global->dstart = ft_max(0, global->dstart);
	while (global->dstart < global->drawend)
	{
		global->texy = (int)global->postart;
		if (global->texy >= 0 && global->texy < texture->height)
		{
			global->texx = ft_color_texture(global, texture);
			if (global->texx >= 0 && global->texx < texture->width)
			{
				global->color = *(unsigned int *)(texture->addr + \
					(global->texy * texture->line_length) + \
						(global->texx * texture->bits_per_pixel / 8));
				if (global->dstart >= 0 && global->dstart < HEIGHT)
					my_mlx_pixel_put2(global, i, global->dstart, global->color);
			}
		}
		if (global->dstart > HEIGHT)
			return ;
		global->postart += global->step;
		global->dstart++;
	}
}
