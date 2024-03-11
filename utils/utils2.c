/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreiner <rgreiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:56:14 by rgreiner          #+#    #+#             */
/*   Updated: 2024/03/11 18:44:16 by rgreiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_longest_y(t_global *global)
{
	int	len;

	len = 0;
	while (global->map[len])
		len++;
	return (len);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	check_angle_deg(t_global *data, char c)
{
	if (c == 'N')
		data->angle_deg = 0.1;
	else if (c == 'E')
		data->angle_deg = 90.1;
	else if (c == 'S')
		data->angle_deg = 180.1;
	else if (c == 'W')
		data->angle_deg = 270.1;
}