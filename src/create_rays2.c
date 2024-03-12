/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rays2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreiner <rgreiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:17:40 by rgreiner          #+#    #+#             */
/*   Updated: 2024/03/12 15:20:30 by rgreiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	ft_create_rays4(t_global *global, double tmp, double opp)
{
	global->alpha = atan(opp) / M_PI * 180;
	global->angle_deg = tmp - global->alpha;
	return (global->diff_opp);
}

double	ft_create_rays5(t_global *global, double tmp, double opp)
{
	global->alpha = atan(opp) / M_PI * 180;
	global->angle_deg = tmp + global->alpha;
	return (global->diff_opp);
}

void	ft_create_rays6(t_global *global)
{
	init_ray(global);
	ft_search_side_x(global);
	ft_search_side_y(global);
}

void	ft_create_rays7(t_global *global)
{
	if (global->angle_deg >= 360.0)
		global->angle_deg -= 360.0;
	else if (global->angle_deg < 0.0)
		global->angle_deg = 360.0 + global->angle_deg;
}
