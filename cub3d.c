/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <ogregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:06:22 by rgreiner          #+#    #+#             */
/*   Updated: 2024/02/14 14:39:02 by ogregoir         ###   ########.fr       */
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
	ft_minimap(&global);
}