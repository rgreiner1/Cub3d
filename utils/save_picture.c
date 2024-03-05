/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_picture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <ogregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:25:57 by ogregoir          #+#    #+#             */
/*   Updated: 2024/03/05 19:28:17 by ogregoir         ###   ########.fr       */
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
	
	
	picture.ref = mlx_xpm_file_to_image(global->mlx \
		, path, &picture.width, &picture.height);
	return (picture);
}

void	save_picture(t_global *global)
{
	printf("PASS\n");
	global->data.wall_n = init_pic(global, "Capitaine_Ferjul.xpm");
	printf("dt no = %s\n", global->data.no);
	//fd = open("pictures/Damien_Jones.xpm", R_OK);
	//printf("fd = %d\n", fd);
	/*printf("PASS\n");
	global->data.wall_e = init_pic(global, global->data.ea);
	global->data.wall_s = init_pic(global, global->data.so);
	global->data.wall_o = init_pic(global, global->data.we);
	printf("PASS\n");*/
	mlx_put_image_to_window(global->mlx, global->win, global->data.wall_n.ref, 0, 0);
}
