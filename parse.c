/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreiner <rgreiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:31:46 by ogregoir          #+#    #+#             */
/*   Updated: 2024/02/09 18:50:10 by rgreiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	verif_cub(char *argv)
{
	int		i;

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

void ft_axe_y(int fd, t_global *global)
{
    char    *str;

    str = get_next_line(fd);
    while(str != NULL)
    {
        global->height++;
        free(str);
        str = get_next_line(fd);
    }
    close(fd);
}

char	**init_cpy(t_global *global)
{
	//Cpy depuis la pos de la map dans le fichier de config
	char	**cp;
	int		i;

	i = -1;
	cp = malloc(sizeof(char *) * (global->height + 1));
	while (++i < global->height)
		cp[i] = ft_strcpy(cp[i], global->map[i]);
	cp[i] = NULL;
	return (cp);
}

char	ft_init_player(t_global *global)
{
	if (global->player == 1)
		return ('N');
	if (global->player == 2)
		return ('E');
	if (global->player == 3)
		return ('W');
	if (global->player == 4)
		return ('S');
	return ('2');
}

void	print_map(char **cpy)
{
	int	i;

	i = 0;
	while(cpy[i])
	{
		printf("%s",cpy[i]);
		i++;
	}
}

void is_closed(t_global *global)
{
    char	**cpy;
	char	player;
	int		x;
	int		y;
    
	cpy = init_cpy(global);
	//player = ft_init_player(global);
	player = 'N';
	while (check_object(cpy, player) == 1)
	{
	x = player_pos_x(cpy, player);
	y = player_pos_y(cpy, player);
	if (cpy[y + 1][x] != player && cpy[y + 1][x] != 'X')
		cpy[y + 1][x] = player;
	if (cpy[y - 1][x] != player && cpy[y - 1][x] != 'X')
		cpy[y - 1][x] = player;
	if (cpy[y][x + 1] != player  && cpy[y][x + 1] != 'X')
		cpy[y][x + 1] = player;
	if (cpy[y][x - 1] != player && cpy[y][x - 1] != 'X')
		cpy[y][x - 1] = player;
	cpy[y][x] = 'X';
	}
	print_map(cpy);
}

void parsing_map(char **argv, t_global *global)
{
    int     fd;
    int     i;

    i = 0;
    verif_cub(argv[1]);
    fd = open(argv[1], O_RDONLY);
    ft_axe_y(fd, global);
    fd = open(argv[1], O_RDONLY);
    global->map = malloc((sizeof(char *) * (global->height + 1)) + 1);
    global->map[i] = get_next_line(fd);
    while(global->map[i] != NULL)
    {
        i++;
        global->map[i] = get_next_line(fd);
    }
    i++;
    global->map[i] = NULL;
    close(fd);
	//is_closed(global);
}
