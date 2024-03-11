/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreiner <rgreiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:33:47 by ogregoir          #+#    #+#             */
/*   Updated: 2024/03/11 18:16:31 by rgreiner         ###   ########.fr       */
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
	double			step;
	double			postart;
	int				texy;
	int				texx;
	unsigned int	color;

	step = 1.0 * texture->height / lineh;
	postart = (global->drawstart - HEIGHT / 2 + lineh / 2) * step;
	global->drawstart = ft_max(0, global->drawstart);
	while (global->drawstart < global->drawend)
	{
		texy = (int)postart;
		if (texy >= 0 && texy < texture->height)
		{
			texx = ft_color_texture(global, texture);
			if (texx >= 0 && texx < texture->width)
			{
				color = *(unsigned int *)(texture->addr + \
					(texy * texture->line_length) + \
						(texx * texture->bits_per_pixel / 8));
				if (global->drawstart >= 0 && global->drawstart < HEIGHT)
					my_mlx_pixel_put2(global, i, global->drawstart, color);
			}
		}
		if (global->drawstart > HEIGHT)
			return ;
		postart += step;
		global->drawstart++;
	}
}
