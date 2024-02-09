/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <ogregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:45:50 by ogregoir          #+#    #+#             */
/*   Updated: 2024/02/09 18:46:20 by ogregoir         ###   ########.fr       */
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
	int     len;

	len = ft_strlen(temp);
	if(len == 3)
	{
		if(temp[0] < 48 && temp[0] > 50)
			ft_error("the color is not between 0 and 255");
		else if(temp[0] == 50 && (temp[1] < 48 && temp[1] > 53))
			ft_error("the color is not between 0 and 255");
		else if(temp[1] == 53 && (temp[2] < 48 && temp[2] > 53))
			ft_error("the color is not between 0 and 255");
	}
}

static int *ft_copy_int(char *str, int j)
{
	int         *color;
	char        **s;
	char        *temp;
	int         i;
	int         l;

	i = 0;
	l = 0;
	color = malloc(sizeof(int) * 3);
	temp = ft_substr(str, j + 1, ft_strlen(str));
	s = ft_split(temp, ',');
	free(temp);
	while(s[i])
	{    
		j = 0;
		while(s[i][j])
		{
			if((s[i][j] != 32 || s[i][j] != '\0') && \
				(s[i][j] >= 48 && s[i][j] <= 57))
			{
				temp[j] = s[i][j];
			}
			j++;
		}
		if(temp != NULL)
		{
			ft_range_color(temp);
			color[l] = ft_atoi(temp);
			l++;
			free(temp);
		}
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
		else if (global->map[i] != NULL)
			ft_error("string not authorize");
		i++;
	}
}