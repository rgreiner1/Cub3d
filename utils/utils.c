/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:29:14 by ogregoir          #+#    #+#             */
/*   Updated: 2024/02/11 00:42:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    ft_error(char *str)
{
	ft_putendl_fd("error", 1);
    ft_putendl_fd(str, 1);
    exit(1);
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