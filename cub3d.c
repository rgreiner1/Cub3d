/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <ogregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:06:22 by rgreiner          #+#    #+#             */
/*   Updated: 2024/02/27 19:48:03 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_global	global;
	int			start;

	(void)argc;
	start = 0;
	parsing_map(argv, &global);
	ft_save_map(&global, start);
	verif_map(&global);
	ft_color(&global);
	ft_minimap(&global);
}
