/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <ogregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:29:14 by ogregoir          #+#    #+#             */
/*   Updated: 2024/02/27 20:37:28 by ogregoir         ###   ########.fr       */
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
	
	str = malloc(2);
	color1 = original;
	if (color1 > 16)
		color1 = color1 / 16;
	color2 = original % 16;
	str[0] = ft_convert_char(color1);
	str[1] = ft_convert_char(color2);
	printf("%s\n", str);
	return (str);
}

int		ft_hti(char *str)
{
    int	i;
	int	value;
	
	i = 0;
	value = 0;
    while (str[i]) 
	{
        if (str[i] >= '0' && str[i] <= '9')
            value = (value << 4) | (str[i] - '0');
        else if (str[i] >= 'A' && str[i] <= 'F')
            value = (value << 4) | (str[i] - 'A' + 10);
		i++;
    }
    return (value);
}

void	ft_color(t_global *global)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strjoin("0x", ft_convert_color(global->data.color_c[i]));
	while (global->data.color_c[i])
	{
		i++;
		str = ft_strjoin(str, ft_convert_color(global->data.color_c[i]));
	}
	printf("%s\n", str);
	global->color_hex_c = ft_hti(str);
	printf("color_c = %ld\n", global->color_hex_c);
}