/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreiner <rgreiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:14:51 by rgreiner          #+#    #+#             */
/*   Updated: 2024/02/10 15:31:41 by rgreiner         ###   ########.fr       */
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
void	is_closed(t_global *global);
void	ft_verif_map_content(char **cpy, int player, int i, int j);

//utils
void    ft_error(char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_longest(t_global *global);

#endif
