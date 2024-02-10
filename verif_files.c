/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:45:50 by ogregoir          #+#    #+#             */
/*   Updated: 2024/02/10 22:49:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_order_files(int i, char *s, int data, char *str)
{
	int	j;

	j = 0;
	while(s[j] != 32)
		j++;
	j += 2;
	if(data < i)
		data = i;
	str = ft_copy_string(s, j);
	return(data);
}

int	ft_order_files2(int i, char *s, int data, int *tab)
{
	int	j;

	j = 0;
	while(s[j] != 32)
		j++;
	j += 1;
	if(data < i)
		data = i;
	tab = ft_copy_int(s, j);
	return(data);
}

void	ft_error_files(t_global *global, int map, int data)
{
	if(map == 0)
		ft_error("there is no map");
	if (data > map)
		ft_error("the map is not in the right place");
	if(global->data.NO == NULL || global->data.SO == NULL || \
		global->data.WE == NULL || global->data.EA == NULL)
	{
		ft_error("not enough arguments about direction");
	}
	if(!global->data.color_f[0] || !global->data.color_c[0])
		ft_error("not enough arguments about colors");
}

int ft_save_data(t_global *global)
{
	int i;
	int j;
	int	map;
	int data;

	i = 0;
	map = 0;
	data = 0;
	while(global->map[i])
	{
		j = 0;
		while(global->map[i][j] == 32)
			j++;
		if(ft_strncmp(global->map[i], "NO", j + 2) == 0 && global->data.NO == NULL)
			data = ft_order_files(i, global->map[i], data, global->data.NO);
		else if(ft_strncmp(global->map[i], "SO", j + 2) == 0 && global->data.SO == NULL)
			data = ft_order_files(i, global->map[i], data, global->data.SO);
		else if(ft_strncmp(global->map[i], "WE", j + 2) == 0 && global->data.WE == NULL)
			data = ft_order_files(i, global->map[i], data, global->data.WE);
		else if(ft_strncmp(global->map[i], "EA", j + 2) == 0 && global->data.EA == NULL)
			data = ft_order_files(i, global->map[i], data, global->data.EA);
		else if(global->map[i][j] == 'F')
			data = ft_order_files2(i, global->map[i], data, global->data.color_f);
		else if(global->map[i][j] == 'C')
			data = ft_order_files2(i, global->map[i], data, global->data.color_c);
		else if (ft_strchr(global->map[i], '1') != 0)
		{
			if(ft_strchr(global->map[i + 1], '\n') != 0 && ft_strchr(global->map[i], '1') == 0)
				ft_error("error1");
			map = i;
			break;		
		}
		i++;
	}
	ft_error_files(global, map, data);
	return(i);
}