/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreiner <rgreiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:10:04 by rgreiner          #+#    #+#             */
/*   Updated: 2024/02/13 16:29:28 by rgreiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

void    ft_move(t_global *global, int move)
{
    if (move == 1)
        global->pos_player_x -= 1;
    if (move == 2)
        global->pos_player_x += 1;
    if (move == 3)
        global->pos_player_y -= 1;
    if (move == 4)
        global->pos_player_y += 1;
    printf("player pos x = %d\n", global->pos_player_x);
    printf("player pos y = %d\n", global->pos_player_y);
    create_object(global, 0xedeb6d);
    init_map(global, 0, 0);
}

int    ft_destroy(t_global *global)
{
    mlx_destroy_window(global->img.mlx, global->img.win);
    //free global
	exit (EXIT_SUCCESS);
}

int    ft_check_key(int keycode, t_global *global)
{
    if (keycode == 65307)
		ft_destroy(global);
    if (keycode == 65362)
        {
        ft_move(global, 2);
        printf("Deplacement devant\n");
        }
    if (keycode == 65364)
        {
        ft_move(global, 1);
        printf("Deplacement arriere\n");
        }
    if (keycode == 65361)
        {
        ft_move(global, 3);
        printf("Deplacement gauche\n");
        }
    if (keycode == 65363)
        {
        printf("Deplacement droite\n");
        ft_move(global, 4);
        }
    if (keycode == 119)
        printf("Deplacement camera devant\n"); 
   if (keycode == 115)
        printf("Deplacement camera arriere\n");
    if (keycode == 97)
        printf("Deplacement camera gauche\n");
    if (keycode == 100)
        printf("Deplacement camera droite\n");
    return (0);
}