/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <ogregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:14:51 by rgreiner          #+#    #+#             */
/*   Updated: 2024/02/09 18:46:37 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <fcntl.h>
# include "utils/libft/libft.h"
# include "mlx_linux/mlx.h"

typedef struct s_data
{
    char    *NO;
    char    *WE;
    char    *EA;
    char    *SO;
    int     *color_c;
    int     *color_f;
    


}t_data;

typedef struct s_global
{
    struct s_data   data;
    char            **map;
    int             height;


}t_global;


//parse
void parsing_map(char **argv, t_global *global);

//utils
void    ft_error(char *str);
void    ft_save_data(t_global *global);

#endif
