/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <ogregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:37:34 by rgreiner          #+#    #+#             */
/*   Updated: 2024/03/04 11:53:53 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_draw_wall(t_global *global, int i)
{
	double	tmp_dist;
	int		line;
	int		drawstart;
	int		drawend;

	if (global->ray.dist_x < global->ray.dist_y)
		tmp_dist = global->ray.opp_total_x;
	else
		tmp_dist = global->ray.opp_total_y;
	line = HEIGHT / tmp_dist;
	drawstart = -line / 2 + HEIGHT / 2;
	if (drawstart < 0)
		drawstart = 0;
	drawend = line / 2 + HEIGHT / 2;
	if (drawend > HEIGHT)
		drawend = HEIGHT - 1;
	while (drawstart < drawend)
	{
		my_mlx_pixel_put2(global, i, drawstart, 0xFF0000);
		drawstart++;
	}
}