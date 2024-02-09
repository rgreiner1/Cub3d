/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreiner <rgreiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:29:14 by ogregoir          #+#    #+#             */
/*   Updated: 2024/02/09 16:59:41 by rgreiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    ft_error(char *str)
{
    ft_putendl_fd(str, 1);
    exit(1);
}

int	player_pos_x(char **map, char cmp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == cmp)
				return (j);
		j++;
		}
	j = 0;
	i++;
	}
	return (0);
}

int	player_pos_y(char **map, char cmp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == cmp)
				return (i);
		j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	check_object(char **map, char cmp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == cmp)
				return (1);
		j++;
		}
		j = 0;
		i++;
	}
	return (0);
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