/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <ogregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:45:50 by ogregoir          #+#    #+#             */
/*   Updated: 2024/03/07 13:27:26 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_save_data(t_global *global)
{
	int	i;
	int	j;
	int	data;

	i = 0;
	data = 0;
	while (global->files[i] != NULL)
	{
		j = 0;
		while (global->files[i][j] == 32)
			j++;
		if (ft_strncmp(global->files[i], "NO", j + 2) == 0)
		{
			if (data < i)
				data = i;
			global->data.no = ft_copy_string(global->files[i], j);
		}
		else if (ft_strncmp(global->files[i], "SO", j + 2) == 0)
		{
			if (data < i)
				data = i;
			global->data.so = ft_copy_string(global->files[i], j);
		}
		else if (ft_strncmp(global->files[i], "WE", j + 2) == 0)
		{
			if (data < i)
				data = i;
			global->data.we = ft_copy_string(global->files[i], j);
		}
		else if (ft_strncmp(global->files[i], "EA", j + 2) == 0)
		{
			if (data < i)
				data = i;
			global->data.ea = ft_copy_string(global->files[i], j);
		}
		else if (global->files[i][j] == 'F')
		{
			if (data < i)
				data = i;
			global->data.color_f = ft_copy_int(global->files[i], j);
		}
		else if (global->files[i][j] == 'C')
		{
			if (data < i)
				data = i;
			global->data.color_c = ft_copy_int(global->files[i], j);
		}
		else if (ft_strchr(global->files[i], '1') != 0)
		{
			if (global->files[i + 1][0] == '\n')
				ft_error("map is incorrect");
			break ;
		}
		i++;
	}
	ft_error_files(global, i, data);
	return (i);
}

void	ft_check_space_map(t_global *global, int start)
{
	int	j;

	while (global->files[start] != NULL)
	{
		j = 0;
		while (global->files[start][j] != '\0' && \
			global->files[start][j] != '\n')
		{
			if (global->files[start][j] != 32 && global->files[start][j] != '1' \
				&& global->files[start][j] != '0')
			{
				if (global->files[start][j] != 'N' && \
					global->files[start][j] != 'S' && \
						global->files[start][j] != 'E' && \
							global->files[start][j] != 'W')
				{
					ft_error("string is not valid");
				}
			}
			j++;
		}
		start++;
	}
}

void	ft_save_map(t_global *global, int start)
{
	int	i;
	int	len;

	start = ft_save_data(global);
	i = start;
	len = 0;
	ft_check_space_map(global, start);
	while (global->files[i] != NULL)
		i++;
	len = i - start;
	global->map = malloc(sizeof(char *) * (len + 1));
	i = 0;
	while (global->files[start] && (i != len))
	{
		global->map[i] = ft_strdup(global->files[start]);
		i++;
		start++;
	}
	global->map[i] = NULL;
	global->data.axes_x = i;
	global->data.axes_y = ft_longest(global) - 1;
}
