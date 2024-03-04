# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogregoir <ogregoir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 11:08:57 by rgreiner          #+#    #+#              #
#    Updated: 2024/03/04 11:46:05 by ogregoir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    =	cub3d.c \
			src/parse.c \
			src/parse_walls.c \
			src/draw_wall.c \
			utils/utils.c \
			utils/color.c \
			src/verif_files.c \
			src/verif_files2.c \
			src/mini_map.c \
			src/key_hooks.c \
			src/raycasting.c \
			src/raycasting_delta.c \
			src/move.c \
			
	
OBJS    =   ${SRCS:.c=.o}
RM      =   rm -f
CC		=	gcc
CFLAGS  =   -Wall -Wextra -Werror
NAME	= 	cub3d
LIBFT	=	utils/libft/libft.a
MLX_AR  =   mlx_linux/libmlx.a


$(NAME)	:  $(MLX_AR) $(LIBFT) $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_AR) ${LIBS} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
$(LIBFT) :
	make -C utils/libft
$(MLX_AR) :
	make -C mlx_linux
all:	${NAME}
clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}
	$(RM) $(LIBFT) $(MLX_AR)
	$(RM) $(LIBFT) $(MLX_AR)
	make fclean -C utils/libft
	make clean -C mlx_linux
re:	fclean all
%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@