/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <ogregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:45:50 by ogregoir          #+#    #+#             */
/*   Updated: 2024/03/12 18:54:50 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_wall(t_global *global)
{
	global->data.no = NULL;
	global->data.ea = NULL;
	global->data.we = NULL;
	global->data.so = NULL;
}

int	ft_save_data(t_global *global, int i, int j, int data)
{
	ft_init_wall(global);
	while (global->files[i] != NULL)
	{
		j = 0;
		while (global->files[i][j] == 32)
			j++;
		if (ft_detect_char(global, i, j) == 0 || \
			ft_detect_int(global, i, j) == 0)
		{
			if (i > data)
				data = i;
		}
		else if (ft_strchr(global->files[i], '1') != 0)
		{
			if (global->files[i + 1] != NULL && global->files[i + 1][0] == '\n')
				ft_error("data incorrect");
			break ;
		}
		else if (global->files[i][0] != '\n')
			ft_error("data incorrect");
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

	start = ft_save_data(global, 0, 0, 0);
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
