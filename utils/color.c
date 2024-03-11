/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreiner <rgreiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:29:14 by ogregoir          #+#    #+#             */
/*   Updated: 2024/03/11 17:35:53 by rgreiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	ft_convert_char(int color)
{
	char	c;

	if (color > 9)
	{
		c = (color - 10) + 'A';
	}
	else
		c = color + 48;
	return (c);
}

char	*ft_convert_color(int original)
{
	int		color1;
	int		color2;
	char	*str;

	str = malloc(3);
	color1 = original;
	while (color1 >= 16)
		color1 = color1 / 16;
	color2 = original % 16;
	str[0] = ft_convert_char(color1);
	str[1] = ft_convert_char(color2);
	str[2] = '\0';
	return (str);
}

int	ft_hti(char *str)
{
	int	i;
	int	value;
	int	result;

	i = 0;
	value = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			value = str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			value = (str[i] - 'A' + 10);
		result = (result * 16) + value;
		i++;
	}
	return (result);
}

void	ft_color(t_global *global, char *str, char *s)
{
	char	*tmp;

	tmp = ft_convert_color(global->data.color_c[0]);
	str = ft_strdup(tmp);
	free(tmp);
	tmp = ft_convert_color(global->data.color_c[1]);
	str = ft_strjoin_free(str, tmp);
	free(tmp);
	tmp = ft_convert_color(global->data.color_c[2]);
	str = ft_strjoin_free(str, tmp);
	free (tmp);
	tmp = ft_convert_color(global->data.color_f[0]);
	s = ft_strdup(tmp);
	free (tmp);
	tmp = ft_convert_color(global->data.color_f[1]);
	s = ft_strjoin_free(s, tmp);
	free(tmp);
	tmp = ft_convert_color(global->data.color_f[2]);
	s = ft_strjoin_free(s, tmp);
	free (tmp);
	global->color_hex_c = ft_hti(str);
	global->color_hex_f = ft_hti(s);
	free (str);
	free (s);
}
