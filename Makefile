# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 15:48:51 by nnourine          #+#    #+#              #
#    Updated: 2024/02/28 10:28:43 by asohrabi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Wextra -Werror
LIBMLX = lib/MLX42
LIBFT = lib/libft

HEADERS	= -I ./include -I ${LIBMLX}/include
LIBS_FLAGS = ${LIBMLX}/build/libmlx42.a -ldl -pthread -lm -L/Users/${USER}/.brew/Cellar/glfw/3.4/lib -lglfw -L${LIBFT} -lft
# MORE_FLAGS = -g -Ofast -framework OpenGL -framework AppKit
SRCS = src/so_long.c
OBJ = ${SRCS:.c=.o}

%.o: %.c
	cc ${CFLAGS} ${HEADERS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJ}
	@cmake ${LIBMLX} -B ${LIBMLX}/build
	@make -C ${LIBMLX}/build -j4
	@make -C ${LIBFT}
	cc ${OBJ} ${CFLAGS} ${LIBS_FLAGS} ${MORE_FLAGS} ${HEADERS} -o ${NAME}

clean:
	rm -f ${OBJ}
	@make -C ${LIBFT} clean
	@rm -rf ${LIBMLX}/build

fclean: clean
	rm -f ${NAME}
	@make -C ${LIBFT} fclean

re: fclean all 

.PHONY: all clean fclean re
