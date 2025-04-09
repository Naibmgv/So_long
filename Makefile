# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/05 10:41:43 by nmagamad          #+#    #+#              #
#    Updated: 2025/04/09 13:15:30 by nmagamad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c so_long_key_bind.c parcing.c parcing_1.c utils.c utils_1.c utils_2.c utils_3.c
OBJS = ${SRCS:.c=.o}
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
RM = rm -rf
LIBFT = ./libft
INCLUDES = -I/usr/include -Imlx -Iincludes
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

all : ${NAME}

${NAME}: ${OBJS}
	${MAKE} -C ./libft/
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ./libft/libft.a ${MLX_FLAGS}

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
	${MAKE} clean -C ./libft/
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} ./libft/libft.a

re: fclean all

.PHONY: all clean fclean re