/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreiner <rgreiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:29:14 by ogregoir          #+#    #+#             */
/*   Updated: 2024/02/10 12:31:25 by rgreiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    ft_error(char *str)
{
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