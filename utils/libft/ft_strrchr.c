/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <ogregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:00:47 by ogregoir          #+#    #+#             */
/*   Updated: 2024/02/09 11:45:21 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int s)
{
	int	i;

	i = ft_strlen((char *)str);
	while (i >= 0)
	{
		if ((char)s == str[i])
			return ((char *)str + i);
		i--;
	}
	return (0);
}
