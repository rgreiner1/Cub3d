/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_picture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:25:57 by ogregoir          #+#    #+#             */
/*   Updated: 2024/03/10 20:10:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_mlx(t_global *global)
{
	global->mlx = mlx_init();
	global->win = mlx_new_window(global->mlx, WIDTH, HEIGHT, "cub3d");
}

static t_img	*init_pic(t_global *global, char *path)
{
	t_img	*picture;
	
	picture = malloc(sizeof(t_img));
	if (open(path, R_OK) == -1)
		ft_error("incorrect PATH");
	picture->ref = mlx_xpm_file_to_image(global->mlx \
		, path, &picture->width, &picture->height);
	if (picture->ref == NULL)
		ft_error("incorrect PATH");
	picture->addr = mlx_get_data_addr(picture->ref, &picture->bits_per_pixel, &picture->line_length, &picture->endian);
	printf("path = %s addr = %d\n", path, *(int *)picture->addr);
	return (picture);
}

void	save_picture(t_global *global)
{	
	global->data.wall_n = init_pic(global, global->data.no);
	global->data.wall_e = init_pic(global, global->data.ea);
	global->data.wall_s = init_pic(global, global->data.so);
	global->data.wall_o = init_pic(global, global->data.we);
}
