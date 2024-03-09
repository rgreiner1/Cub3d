/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <ogregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:33:47 by ogregoir          #+#    #+#             */
/*   Updated: 2024/03/09 19:53:43 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int    ft_color_texture(t_global *global)
{
    double    wallx;
    int        texx;
    
    if (global->ray.dist_x < global->ray.dist_y)
        wallx = global->ray.pos_x_y - floor(global->ray.pos_x_y);
    else
        wallx = global->ray.pos_y_x - floor(global->ray.pos_y_x);
    texx = wallx * global->data.wall_n.width;
    texx = global->data.wall_n.width - texx - 1;
	return(texx);
}

void	ft_text(t_global *global, int i, int drawstart, int drawend)
{
	double			step;
	double			postart;
	int				lineH;
	int				texY;
	unsigned int	color;
	
	lineH = drawend - drawstart;
	step = global->data.wall_n.height / lineH;
	postart = (drawstart - HEIGHT / 2 + lineH / 2) * step;
	while (drawstart < drawend)
	{
		texY = (int)postart & (global->data.wall_n.height - 1);
		postart += step;
		color = *(int *)(global->data.wall_n.addr + (texY * global->data.wall_n.line_length) + ((ft_color_texture(global)) * global->data.wall_n.bits_per_pixel / 8));
		my_mlx_pixel_put2(global, i, drawstart, color);
		drawstart++;
	}
}