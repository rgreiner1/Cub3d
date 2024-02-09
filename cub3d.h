/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreiner <rgreiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:14:51 by rgreiner          #+#    #+#             */
/*   Updated: 2024/02/09 16:46:22 by rgreiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <fcntl.h>
# include "utils/libft/libft.h"
# include "mlx_linux/mlx.h"

typedef struct s_global
{
  //  struct s_data   data;
    char            **map;
    int				player;
    int             height;
}t_global;
/*
typedef struct s_data
{


}t_data;*/

//parse
void parsing_map(char **argv, t_global *global);

//utils
void    ft_error(char *str);
int		player_pos_y(char **map, char cmp);
int		player_pos_x(char **map, char cmp);
int		check_object(char **map, char cmp);
char	*ft_strcpy(char *dest, char *src);


#endif
