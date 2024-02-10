/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:45:50 by ogregoir          #+#    #+#             */
/*   Updated: 2024/02/10 14:25:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static char *ft_copy_string(char *str, int j)
{
	int     start;
	char    *s;
	
	start = 0;
	s = NULL;
	j += 2;
	while(str[j] == 32)
		j++;
	start = j;
	while(str[j] != 32)
		j++;
	s = ft_substr(str, start, j);
	return(s);
}

static void ft_range_color(char *temp)
{
	int	len;
	int	i;

	len = ft_strlen(temp);
	i = 0;
	while(temp[i])
	{
		if(temp[i] == '\n')
			break;
		if(temp[i] >= 48 && temp[i] <= 57)
		{
			if(temp[0] < 48 && temp[0] > 50 && len == 3)
				ft_error("the color is not between 0 and 255");
			else if(temp[2] < 48 && temp[2] > 53 && len == 3)
				ft_error("the color is not between 0 and 255");
			else if(temp[3] < 48 && temp[3] > 53 && len == 3)
				ft_error("the color is not between 0 and 255");
		}
		else
		{
			ft_error("character is not numeric");
		}
		i++;
	}
}

static int *ft_copy_int(char *str, int j)
{
	int         *color;
	char        **s;
	char        *temp;
	int         i;

	i = 0;
	color = malloc(sizeof(int) * 3);
	j += 1;
	while(str[j] == 32)
		j++;
	temp = ft_substr(str, j, ft_strlen(str));
	s = ft_split(temp, ',');
	free(temp);
	while(s[i])
	{
		ft_range_color(s[i]);
		color[i] = ft_atoi(s[i]);
		i++;  
	}
	return(color);
}

void ft_save_data(t_global *global)
{
	int i;
	int j;

	i = 0;
	while(global->map[i])
	{    
		j = 0;
		while(global->map[i][j] == 32)
			j++;
		if(ft_strncmp(global->map[i], "NO", j + 2) == 0 && global->data.NO == NULL)
			global->data.NO = ft_copy_string(global->map[i], j);
		else if(ft_strncmp(global->map[i], "SO", j + 2) == 0 && global->data.SO == NULL)
			global->data.SO = ft_copy_string(global->map[i], j);
		else if(ft_strncmp(global->map[i], "WE", j + 2) == 0 && global->data.WE == NULL)
			global->data.WE = ft_copy_string(global->map[i], j);
		else if(ft_strncmp(global->map[i], "EA", j + 2) == 0 && global->data.EA == NULL)
			global->data.EA = ft_copy_string(global->map[i], j);
		else if(global->map[i][j] == 'F')
			global->data.color_f = ft_copy_int(global->map[i], j);
		else if(global->map[i][j] == 'C')
			global->data.color_c = ft_copy_int(global->map[i], j);
	/*	else if (global->map[i] != NULL)
			ft_error("string not authorize");*/
		i++;
	}
}

int	ft_order_files(t_global *global)
{
	int	i;
	int	j;
	int	save;

	i = 0;
	j = 0;
	save = 0;
	while(global->map[i])
	{
		if(ft_strncmp(global->map[i], global->data.NO, ft_strlen(global->map[i])) == 0 || \
			ft_strncmp(global->map[i], global->data.WE, ft_strlen(global->map[i])) == 0 || \
			ft_strncmp(global->map[i], global->data.EA, ft_strlen(global->map[i])) == 0 || \
			ft_strncmp(global->map[i], global->data.SO, ft_strlen(global->map[i])) == 0)
		{
			if(save < i)
				save = i;
		}
		else if (ft_strncmp(global->map[i], global->data.color_c, ft_strlen(global->map[i])) == 0 || \
			ft_strncmp(global->map[i], global->data.color_f, ft_strlen(global->map[i])) == 0)
		{
			if(save < i)
				save = i;
		}
		else if (ft_strchr(global->map[i], '1') != 0)
			
		
	}
}