/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_files2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 22:28:03 by marvin            #+#    #+#             */
/*   Updated: 2024/02/10 22:28:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_copy_string(char *str, int j)
{
	int		start;
	char	*s;

	start = 0;
	s = NULL;
	j += 2;
	while (str[j] == 32)
		j++;
	start = j;
	while (str[j] != 32)
		j++;
	s = ft_substr(str, start, j);
	return (s);
}

void	ft_range_color(char *temp)
{
	int	len;
	int	i;

	len = ft_strlen(temp);
	i = -1;
	if (len > 3)
		ft_error("a color is not correct");
	while (temp[++i])
	{
		if (temp[i] == '\n')
			break ;
		if (temp[i] >= 48 && temp[i] <= 57)
		{
			if (temp[0] < 48 && temp[0] > 50 && len == 3)
				ft_error("the color is not between 0 and 255");
			else if (temp[2] < 48 && temp[2] > 53 && len == 3)
				ft_error("the color is not between 0 and 255");
			else if (temp[3] < 48 && temp[3] > 53 && len == 3)
				ft_error("the color is not between 0 and 255");
		}
		else
		{
			ft_error("character is not numeric");
		}
	}
}

char	*ft_sup_space(char *str)
{
	int		len;
	int		i;
	char	*s;

	i = 0;
	len = ft_strlen(str);
	s = NULL;
	while (str[i] == 32)
		i++;
	while (str[len] != ft_isdigit(str[len]))
		len--;
	len -= i;
	s = ft_substr(str, i, len);
	return (s);
}

int	*ft_copy_int(char *str, int j)
{
	int		*color;
	char	**s;
	char	*temp;
	int		i;

	i = 0;
	color = malloc(sizeof(int) * 3);
	j += 1;
	while (str[j] == 32)
		j++;
	temp = ft_substr(str, j, ft_strlen(str));
	s = ft_split(temp, ',');
	free(temp);
	while (s[i])
	{
		temp = ft_sup_space(s[i]);
		ft_range_color(temp);
		color[i] = ft_atoi(temp);
		i++;
	}
	free(temp);
	return (color);
}
