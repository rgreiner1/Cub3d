/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreiner <rgreiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:31:46 by ogregoir          #+#    #+#             */
/*   Updated: 2024/02/10 16:11:40 by rgreiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	verif_cub(char *argv)
{
	int	i;

	i = ft_strlen(argv);
	if (i < 5)
		ft_error("error map.cub");
	if (!ft_strrchr(argv, '.') || \
		ft_strncmp(ft_strrchr(argv, '.'), ".cub", 5) != 0)
		ft_error("error map.cub");
	if (!ft_strrchr(argv, '.') || \
		ft_strncmp(ft_strrchr(argv, '.'), argv, 5) == 0)
		ft_error("error map.cub");
	if (ft_strrchr(argv, '.') && ft_strrchr(argv, '/') && \
		ft_strncmp(ft_strrchr(argv, '.'), ft_strrchr(argv, '/') + 1, 5) == 0)
		ft_error("error map.cub");
}

void	ft_axe_y(int fd, t_global *global)
{
	char	*str;

	str = get_next_line(fd);
	while (str != NULL)
	{
		global->height++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
}

int	ft_longest(t_global *global)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(global->map[i]);
	while (global->map[i])
	{
		if (j < (int)ft_strlen(global->map[i]))
			j = ft_strlen(global->map[i]);
		i++;
	}
	return (j);
}

void	ft_verif_map_content(char **cpy, int player, int i, int j)
{
	while (cpy[i])
	{
		j = 0;
		while (cpy[i][j])
		{
			if (cpy[i][j] == 'N' || cpy[i][j] == 'S' || \
			cpy[i][j] == 'E' || cpy[i][j] == 'W')
				player++;
			if (player > 1)
				ft_error("Error, multiples players");
			if (cpy[i][j] != 'N' && cpy[i][j] != 'S' && \
			cpy[i][j] != 'E' && cpy[i][j] != 'W' && cpy[i][j] != 32 && \
			cpy[i][j] != '0' && cpy[i][j] != '1' && cpy[i][j] != '\n')
				ft_error("Error, invalid characters");
			j++;
		}
		i++;
	}
	if (player != 1)
		ft_error("Error, No player");
}

void	parsing_map(char **argv, t_global *global)
{
	int	fd;
	int	i;

	i = 0;
	verif_cub(argv[1]);
	fd = open(argv[1], O_RDONLY);
	ft_axe_y(fd, global);
	fd = open(argv[1], O_RDONLY);
	global->map = malloc((sizeof(char *) * (global->height + 1)) + 1);
	global->map[i] = get_next_line(fd);
	while (global->map[i] != NULL)
	{
		i++;
		global->map[i] = get_next_line(fd);
	}
	i++;
	global->map[i] = NULL;
	close(fd);
	verif_map(global);
}
