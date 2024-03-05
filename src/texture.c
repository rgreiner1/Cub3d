/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <ogregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:33:47 by ogregoir          #+#    #+#             */
/*   Updated: 2024/03/05 17:36:18 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_mlx(t_global *global)
{
	global->mlx = mlx_init();
	global->win = mlx_new_window(global->mlx, WIDTH, HEIGHT, "cub3d");
}

