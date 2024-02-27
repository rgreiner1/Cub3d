/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreiner <rgreiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:29:14 by ogregoir          #+#    #+#             */
/*   Updated: 2024/02/27 19:08:13 by rgreiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error(char *str)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd(str, 1);
	exit(1);
}

void	ft_print_map(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("map = %s", str[i]);
		i++;
	}
}

char	*ft_strcpy(char *dest, char *src)
{
	int	w;

	w = 0;
	dest = malloc(sizeof(*dest) * ft_strlen(src) + 1);
	while (src[w] != '\0')
	{
		dest[w] = src[w];
		w++;
	}
	dest[w] = '\0';
	return (dest);
}

void	ft_error_files(t_global *global, int map, int data)
{
	if (map == global->height)
		ft_error("there is no map");
	if (data == 0 || data >= map)
		ft_error("the map is not in the right place");
	if (!global->data.no || !global->data.so || \
		!global->data.we || !global->data.ea)
	{
		ft_error("not enough arguments about direction");
	}
	if (!global->data.color_f || !global->data.color_c)
		ft_error("not enough arguments about colors");
}

void	my_mlx_pixel_put(t_global *global, int x, int y, int color)
{
	char	*dst;

	dst = global->img.addr + \
		(y * global->img.line_length + x * (global->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_pixel_put2(t_global *global, int x, int y, int color)
{
	char	*dst;

	dst = global->game.addr + \
		(y * global->game.line_length + x * (global->game.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}