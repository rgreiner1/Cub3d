/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:33:47 by ogregoir          #+#    #+#             */
/*   Updated: 2024/03/10 20:08:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_img	*correct_text(t_global *global)
{
	if (global->ray.dist_x < global->ray.dist_y && (global->angle_deg > 180 && global->angle_deg < 360)) //droite
		return (global->data.wall_o);
	else if (global->ray.dist_x > global->ray.dist_y && (global->angle_deg > 90 && global->angle_deg < 270)) //sud
		return (global->data.wall_s);
	else if (global->ray.dist_x < global->ray.dist_y && (global->angle_deg < 180 && global->angle_deg > 0)) // gauche
		return (global->data.wall_e);
	else
		return (global->data.wall_n);
}

int    ft_color_texture(t_global *global, t_img *texture)
{
    double    wallx;
    int        texx;

    if (global->ray.dist_x < global->ray.dist_y)
		wallx = global->ray.pos_x_y - floor(global->ray.pos_x_y);
    else
		wallx = global->ray.pos_y_x - floor(global->ray.pos_y_x);
    texx = wallx * texture->width;
	if (global->ray.dist_x < global->ray.dist_y && (global->angle_deg > 180 && global->angle_deg < 360))
		texx = texture->width - texx - 1;
	if (global->ray.dist_x > global->ray.dist_y && (global->angle_deg > 90 && global->angle_deg < 270))
		texx = texture->width - texx - 1;
	return(texx);
}

void	ft_text(t_global *global, int i, int drawstart, int drawend, t_img *texture)
{
	double			step;
	double			postart;
	int				lineH;
	int				texY;
	int				texX;
	unsigned int	color;
	
	lineH = drawend - drawstart;
	step = 1.0 * texture->height / lineH;
	postart = (drawstart - HEIGHT / 2 + lineH / 2) * step;

	while (drawstart < drawend)
	{	
		texY = (int)postart;
		if (texY >= 0 && texY < texture->height)
		{
			texX = ft_color_texture(global, texture);
			if (texX >= 0 && texX < texture->width)
			{
				color = *(unsigned int *)(texture->addr + (texY * texture->line_length) + (texX * texture->bits_per_pixel / 8));
				my_mlx_pixel_put2(global, i, drawstart, color);
			}
		}
		postart += step;
		//if (global->ray.dist_x > global->ray.dist_y)
		//	color = (color >> 1) & 8355711;
		drawstart++;
	}
}