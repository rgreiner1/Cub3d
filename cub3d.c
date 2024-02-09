/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <ogregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:06:22 by rgreiner          #+#    #+#             */
/*   Updated: 2024/02/09 18:47:53 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{	
	void		*mlx;
	t_global	global;
	//int			i;
	
	(void)mlx;
	(void)argc;
	//i = 0;
	parsing_map(argv, &global);
	ft_save_data(&global);
}