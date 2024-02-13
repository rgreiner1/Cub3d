# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgreiner <rgreiner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 11:08:57 by rgreiner          #+#    #+#              #
#    Updated: 2024/02/13 10:11:22 by rgreiner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    =	cub3d.c \
			parse.c \
			parse_walls.c \
			utils/utils.c \
			verif_files.c \
			verif_files2.c \
			mini_map.c \
			key_hooks.c \
	
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