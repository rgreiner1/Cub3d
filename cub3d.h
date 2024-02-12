/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreiner <rgreiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:14:51 by rgreiner          #+#    #+#             */
/*   Updated: 2024/02/12 17:58:26 by rgreiner         ###   ########.fr       */
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
	char	*no;
	char	*we;
	char	*ea;
	char	*so;
	int		*color_c;
	int		*color_f;
}	t_data;

typedef struct s_global
{
	struct s_data	data;
	char			**map;
	char			**files;
	int				player;
	int				height;
	void			*mlx;
}	t_global;

//parse
void	parsing_map(char **argv, t_global *global);
void	verif_map(t_global *global);
void	ft_verif_map_content(char **cpy, int player, int i, int j);
int		*ft_copy_int(char *str, int j);
char	*ft_copy_string(char *str, int j);
int		ft_save_data(t_global *global);

//utils
void	ft_error(char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_longest(t_global *global);
void	ft_save_map(t_global *global, int start);
void	ft_print_map(char **str);

//Minimap
void    ft_minimap(t_global *global);

#endif
