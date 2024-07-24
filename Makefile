# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amontant <amontant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 14:47:57 by evsuits           #+#    #+#              #
#    Updated: 2023/02/08 17:40:00 by amontant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=	main.c \
		cub3d_hooks.c \
		cub3d_display_lines.c \
		cub3d_draw.c \
		cub3d_init.c \
		cub3d_init_text.c \
		cub3d_vcheck.c \
		cub3d_utils.c \
		cub3d_hcheck.c \
		cub3d_raycasting.c \
		cub3d_move.c \
		cub3d_look.c \
		parsing/parsing.c \
		parsing/check_map.c \
		parsing/check.c \
		parsing/parse_utils.c \
		parsing/free.c \
		parsing/get_next_line_utils.c \
		parsing/get_next_line.c \
		parsing/parse.c \
		parsing/set_check.c \
		parsing/readfile.c \
		parsing/set_map.c \
		parsing/utils.c

CC= gcc

CFLAGS= -g3 -Wall -Wextra -Werror -I/usr/include -Imlx_linux 

HEADERS= parsing/parsing.h \
		 cub3d.h \

OBJS= ${SRCS:.c=.o}

NAME= cub3d

%.o: %.c ${HEADERS}
	${CC} ${CFLAGS}  -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} parsing/libft/libft.a mlx_linux/libmlx_Linux.a
	${CC} ${HEADERS} $^ -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME}

parsing/libft/libft.a :
	cd parsing/libft && make && make clean && cd ../..

mlx_linux/libmlx_Linux.a:
	$(MAKE) -C mlx_linux

clean:
	rm -f ${OBJS}
fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean fclean all re
