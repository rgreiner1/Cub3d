/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <ogregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:04:31 by ogregoir          #+#    #+#             */
/*   Updated: 2024/02/28 13:28:42 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_verif_wall(t_global *global, double step_x, double step_y)
{
	if (global->map[(int)floor(global->pos_player_y + step_y)] \
	[(int)floor(global->pos_player_x + step_x)] != '1')
	{
		if (global->map[(int)floor(global->pos_player_y + step_y)] \
		[(int)floor(global->pos_player_x )] != '1')
		if (global->map[(int)floor(global->pos_player_y)] \
		[(int)floor(global->pos_player_x + step_x )] != '1')
		{
			global->pos_player_x += step_x;
			global->pos_player_y += step_y;
		}
	}
}

void	ft_next_move(t_global *global, int move, double step_x, double step_y)
{
	if (move == 1)
	{
		step_x = 0.1 * sin(global->angle_deg * M_PI / 180);
		step_y = 0.1 * (-cos(global->angle_deg * M_PI / 180));
	}
	if (move == 2)
	{
		step_x = 0.1 * (-sin(global->angle_deg * M_PI / 180));
		step_y = 0.1 * cos(global->angle_deg * M_PI / 180);
	}
	if (move == 3)
	{
		step_x = 0.1 * (-cos(global->angle_deg * M_PI / 180));
		step_y = 0.1 * (-sin(global->angle_deg * M_PI / 180));
	}
	if (move == 4)
	{
		step_x = 0.1 * cos(global->angle_deg * M_PI / 180);
		step_y = 0.1 * sin(global->angle_deg * M_PI / 180);
	}
	ft_verif_wall(global, step_x, step_y);
}

void	ft_create_f_s(t_global *global)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while(y < HEIGHT / 2)
	{
		while (x != WIDTH)
			{
				my_mlx_pixel_put2(global, x, y, global->color_hex_c);
				x++;
			}
	x = 0;
	y++;
	}
	while(y <= HEIGHT)
	{
		while (x != WIDTH)
			{
				my_mlx_pixel_put2(global, x, y, global->color_hex_f);
				x++;
			}
	x = 0;
	y++;
	}

}