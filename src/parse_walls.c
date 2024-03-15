/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreiner <rgreiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:32:24 by rgreiner          #+#    #+#             */
/*   Updated: 2024/03/15 10:15:45 by rgreiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_map_len(char **map)
{
	int	len;

	len = 0;
	while (map[len])
		len++;
	return (len);
}

void	ft_check_wall(t_global *global, char **cpy, int i, int j)
{
	if (i == 0)
		ft_error("Map is not closed by walls");
	if (i == ft_map_len(global->map) - 1)
		ft_error("Map is not closed by walls");
	if (cpy[i - 1][j] == '\n' || cpy[i - 1][j] == 32 || cpy[i - 1][j] == '\0')
		ft_error("Map is not closed by walls");
	if (cpy[i + 1][j] == '\n' || cpy[i + 1][j] == 32 || cpy[i + 1][j] == '\0')
		ft_error("Map is not closed by walls");
	if (cpy[i][j - 1] == '\n' || cpy[i][j - 1] == 32 || cpy[i][j - 1] == '\0')
		ft_error("Map is not closed by walls");
	if (cpy[i][j + 1] == '\n' || cpy[i][j + 1] == 32 || cpy[i][j + 1] == '\0')
		ft_error("Map is not closed by walls");
}

void	verif_map(t_global *global)
{
	char	**cpy;
	int		i;
	int		j;

	cpy = global->map;
	i = 0;
	while (cpy[i])
	{
		j = 0;
		while (cpy[i][j])
		{
			if (cpy[i][j] == '0' || cpy[i][j] == 'N' || cpy[i][j] == 'S' \
				|| cpy[i][j] == 'E' || cpy[i][j] == 'W')
				ft_check_wall(global, cpy, i, j);
			j++;
		}
		i++;
	}
	ft_verif_map_content(cpy, 0, 0, 0);
}

void	ft_verif_comma(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
		{
			if (str[i + 1] != '\0' && str[i + 1] == ',')
				ft_error("too much comma");
		}
		i++;
	}
}
