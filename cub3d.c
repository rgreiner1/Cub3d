/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreiner <rgreiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:06:22 by rgreiner          #+#    #+#             */
/*   Updated: 2024/03/11 16:16:58 by rgreiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_global	global;
	int			start;
	char		*str;
	char		*s;

	if (argc != 2)
		ft_error("Invalid arguments numbers");
	start = 0;
	str = NULL;
	s = NULL;
	parsing_map(argv, &global);
	ft_save_map(&global, start);
	verif_map(&global);
	ft_color(&global, str, s);
	ft_minimap(&global);
}
