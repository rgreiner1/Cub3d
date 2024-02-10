/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreiner <rgreiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:32:24 by rgreiner          #+#    #+#             */
/*   Updated: 2024/02/10 15:31:59 by rgreiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

char	**init_cpy(t_global *global)
{
	//Cpy depuis la pos de la map dans le fichier de config
	char	**cp;
	int		i;

	i = -1;
	cp = malloc(sizeof(char *) * (global->height + 1));
	while (++i < global->height)
		{
			cp[i] = ft_calloc(ft_longest(global),1);
			cp[i] = ft_memcpy(cp[i], global->map[i], ft_strlen(global->map[i]));
		}
	cp[i] = NULL;
	return (cp);
}

void	ft_check_wall(t_global *global, char **cpy, int i, int j)
{
	if (i == 0)
		ft_error("Error, map is not closed by walls");
	if (i == global->height - 1)
		ft_error("Error, map is not closed by walls");
	if (cpy[i - 1][j] == '\n' || cpy[i - 1][j] == 32 || cpy[i - 1][j] == '\0')
		ft_error("Error, map is not closed by walls");
	if (cpy[i + 1][j] == '\n' || cpy[i + 1][j] == 32 || cpy[i + 1][j] == '\0')
		ft_error("Error, map is not closed by walls");
	if (cpy[i][j - 1] == '\n' || cpy[i][j - 1] == 32 || cpy[i][j - 1] == '\0')
		ft_error("Error, map is not closed by walls");
	if (cpy[i][j + 1] == '\n' || cpy[i][j + 1] == 32 || cpy[i][j + 1] == '\0')
		ft_error("Error, map is not closed by walls");
}

void is_closed(t_global *global)
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
				ft_check_wall(global ,cpy, i, j);
			j++;
		}
	i++;
	}
    ft_verif_map_content(cpy, 0, 0, 0);
}


