/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_picture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:25:57 by ogregoir          #+#    #+#             */
/*   Updated: 2024/03/06 17:29:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_img(t_global *global, t_img picture, int y, int x)
{
	mlx_put_image_to_window(global->mlx, global->win, \
		picture.ref, y, x);
}	

static t_img	init_pic(t_global *global, char *path)
{
	t_img	picture;
	
	if (open(path, R_OK) == -1)
		ft_error("incorrect PATH");
	picture.ref = mlx_xpm_file_to_image(global->mlx \
		, path, &picture.width, &picture.height);
	if (picture.ref == NULL)
	{
		printf("ICI\n");
		ft_error("incorrect PATH");
	}
	return (picture);
}

void	save_picture(t_global *global)
{
	global->data.wall_n = init_pic(global, global->data.no);
//	global->data.wall_e = init_pic(global, global->data.ea);
//	global->data.wall_s = init_pic(global, global->data.so);
//	global->data.wall_o = init_pic(global, global->data.we);
	mlx_put_image_to_window(global->mlx, global->win, global->data.wall_n.ref, 0, 0);
}
