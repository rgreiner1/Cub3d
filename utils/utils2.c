/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <ogregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:56:14 by rgreiner          #+#    #+#             */
/*   Updated: 2024/03/12 18:55:37 by ogregoir         ###   ########.fr       */
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

int	ft_detect_char(t_global *g, int i, int j)
{
	if ((ft_strncmp(g->files[i] + j, "NO", 2) == 0) && !g->data.no)
	{
		g->data.no = ft_copy_string(g->files[i], j);
		return (0);
	}
	else if ((ft_strncmp(g->files[i] + j, "SO", 2) == 0) && !g->data.so)
	{
		g->data.so = ft_copy_string(g->files[i], j);
		return (0);
	}
	else if ((ft_strncmp(g->files[i] + j, "WE", 2) == 0) && !g->data.we)
	{
		g->data.we = ft_copy_string(g->files[i], j);
		return (0);
	}
	else if ((ft_strncmp(g->files[i] + j, "EA", 2) == 0) && !g->data.ea)
	{
		g->data.ea = ft_copy_string(g->files[i], j);
		return (0);
	}
	return (1);
}

int	ft_detect_int(t_global *global, int i, int j)
{
	if (global->files[i][j] == 'F' && !global->data.color_f)
	{
		global->data.color_f = ft_copy_int(global->files[i], j);
		return (0);
	}
	else if (global->files[i][j] == 'C' && !global->data.color_c)
	{
		global->data.color_c = ft_copy_int(global->files[i], j);
		return (0);
	}
	return (1);
}
