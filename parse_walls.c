/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:32:24 by rgreiner          #+#    #+#             */
/*   Updated: 2024/02/20 23:41:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_map_len(char **map)
{
	int	len;

	len = 0;
	while (map[len])
		len++;
	return (len);
}

char	**init_cpy(t_global *global)
{
	char	**cp;
	int		i;

	i = -1;
	cp = malloc(sizeof(char *) * (ft_map_len(global->map) + 1));
	while (++i < ft_map_len(global->map))
	{
		cp[i] = ft_calloc(ft_longest(global), 1);
		cp[i] = ft_memcpy(cp[i], global->map[i], ft_strlen(global->map[i]));
	}
	cp[i] = NULL;
	return (cp);
}

void	ft_check_wall(t_global *global, char **cpy, int i, int j)
{
	if (i == 0)
		ft_error("Map is not closed by walls");
	if (i == global->height - 1)
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

	cpy = init_cpy(global);
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
