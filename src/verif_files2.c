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

#include "../cub3d.h"

char	*ft_copy_string(char *str, int j)
{
	int		start;
	int		len;
	char	*s;

	start = 0;
	len = 0;
	s = NULL;
	j += 2;
	while (str[j] == 32)
		j++;
	start = j;
	while (str[j] != 32 && str[j] != '\0')
	{
		len++;
		j++;
	}
	s = ft_substr(str, start, len);
	return (s);
}

int	check_space(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] == 32)
		i++;
	while (ft_isdigit(str[i]) == 1)
	{
		len++;
		i++;
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			ft_error("number format is incorrect");
		i++;
	}
	return (len);
}

char	*ft_sup_space(char *str)
{
	int		i;
	int		len;
	char	*s;

	i = 0;
	len = 0;
	s = NULL;
	while (str[i])
	{
		if ((ft_isdigit(str[i]) == 0) && str[i] != 32 && str[i] != '\n')
			ft_error("character is not numeric");
		i++;
	}
	len = check_space(str);
	s = ft_substr(str, 0, len);
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
		color[i] = ft_atoi(temp);
		if (color[i] < 0 || color[i] > 255)
			ft_error("the color is not between 0 and 255");
		i++;
	}
	free(temp);
	return (color);
}
