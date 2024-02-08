# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgreiner <rgreiner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 11:08:57 by rgreiner          #+#    #+#              #
#    Updated: 2024/02/08 17:08:58 by rgreiner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    =	cub3d.c
	
OBJS    =   ${SRCS:.c=.o}
RM      =   rm -f
CC		=	gcc
CFLAGS  =   -Wall -Wextra -Werror
NAME	= 	cub3d
LIBFT	=	libft/libft.a

$(NAME)	:  $(LIBFT) $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) ${LIBS} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
$(LIBFT) :
	make -C libft
	
all:	${NAME}
clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}
	$(RM) $(LIBFT)
	make fclean -C libft
re:	fclean all
%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@