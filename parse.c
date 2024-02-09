/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <ogregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:31:46 by ogregoir          #+#    #+#             */
/*   Updated: 2024/02/09 13:35:22 by ogregoir         ###   ########.fr       */
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
}
