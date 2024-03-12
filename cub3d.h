/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreiner <rgreiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:14:51 by rgreiner          #+#    #+#             */
/*   Updated: 2024/03/12 19:01:07 by rgreiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define SIZE_MAP 8.0
# define HEIGHT 1080.0
# define WIDTH 1920.0
# define FOV 60.0
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "utils/libft/libft.h"
# include "mlx_linux/mlx.h"
# include <math.h>

typedef struct s_img
{
	void	*ref;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_data
{
	char			*no;
	char			*we;
	char			*ea;
	char			*so;
	int				*color_c;
	int				*color_f;
	int				axes_x;
	int				axes_y;
	t_img			*wall_n;
	t_img			*wall_s;
	t_img			*wall_e;
	t_img			*wall_o;
}	t_data;

typedef struct s_ray
{
	double	ang_x;
	double	ang_y;
	double	side_x;
	double	side_y;
	double	side_x_dist;
	double	side_y_dist;
	double	side_y_x;
	double	side_y_y;
	double	side_x_x;
	double	side_x_y;
	double	dist_x;
	double	pos_x_y;	
	double	pos_x_x;
	double	dist_y;
	double	pos_y_x;
	double	pos_y_y;
}	t_ray;

typedef struct s_global
{
	struct s_data	data;
	struct s_img	minimap;
	t_img			game;
	struct s_ray	ray;
	void			*mlx;
	void			*win;
	double			angle_deg;
	char			**map;
	char			**files;
	double			pos_player_y;
	double			pos_player_x;
	int				color_hex_c;
	int				color_hex_f;
	int				height;
	double			cpy_angle_deg;
	int				dstart;
	int				drawend;
	int				texy;
	int				texx;
	double			step;
	double			postart;
	unsigned int	color;
	double			diff_opp;
	double			alpha;
}	t_global;

//parse
void	parsing_map(char **argv, t_global *global);
void	verif_map(t_global *global);
void	ft_verif_map_content(char **cpy, int player, int i, int j);
int		*ft_copy_int(char *str, int j);
char	*ft_copy_string(char *str, int j);
int		ft_save_data(t_global *global, int i, int j, int data);

//utils
void	ft_error(char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_longest(t_global *global);
int		ft_longest_y(t_global *global);
void	ft_save_map(t_global *global, int start);
void	ft_print_map(char **str);

//Minimap
void	ft_minimap(t_global *global);
void	init_map(t_global *global, int i, int j);

//Deplacement
int		ft_destroy(t_global *global);
int		ft_check_key(int keycode, t_global *global);
void	create_object(t_global *global, int color);
void	ft_create_ray(t_global *global, int color);

void	check_angle_deg(t_global *data, char c);
void	ft_search_side_x(t_global *data);
void	ft_search_side_y(t_global *data);
void	ft_delta_x(t_global *data);
void	ft_delta_y(t_global *data);

void	ft_error_files(t_global *global, int map, int data);
void	my_mlx_pixel_put(t_global *global, int x, int y, int color);
void	my_mlx_pixel_put2(t_global *global, int x, int y, int color);
void	init_ray(t_global *data);
void	ft_create_rays(t_global *global, double tmp, double i, double opp);
void	ft_next_move(t_global *global, int move, double step_x, double step_y);
void	ft_create_f_s(t_global *global);
void	ft_color(t_global *global, char *str, char *s);
void	ft_draw_wall(t_global *global, int i);
void	put_img(t_global *global, t_img picture, int y, int x);
void	save_picture(t_global *global);
void	ft_init_mlx(t_global *global);
void	ft_text(t_global *global, int i, t_img *texture, int lineh);
t_img	*correct_text(t_global *global);
void	free_char(char **str);
int		ft_max(int a, int b);
int		ft_detect_int(t_global *global, int i, int j);
int		ft_detect_char(t_global *g, int i, int j);
double	ft_create_rays4(t_global *global, double tmp, double opp);
double	ft_create_rays5(t_global *global, double tmp, double opp);
void	ft_create_rays6(t_global *global);
void	ft_create_rays7(t_global *global);

#endif
