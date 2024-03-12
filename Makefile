# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 15:48:51 by asohrabi          #+#    #+#              #
#    Updated: 2024/03/12 11:20:15 by asohrabi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Add explanation about installing cmake and glfw
#Fix that home address

NAME = so_long
CFLAGS = -Wall -Wextra -Werror
LIBMLX = lib/MLX42
LIBFT = lib/libft
# USER = alireza
HEADERS	= -I include -I ${LIBMLX}/include
LIBS_FLAGS = ${LIBMLX}/build/libmlx42.a -ldl -pthread -lm -L/Users/${USER}/.brew/Cellar/glfw/3.4/lib -lglfw -L${LIBFT} -lft
# MORE_FLAGS = -g -Ofast -framework OpenGL -framework AppKit
# form git mlx42, other flags (for macos) = -lglfw(3) -framework Cocoa -framework OpenGL -framework IOKit
# remember to delete this
DEBUG_FLAG = -DDEBUG=1
SRCS = src/so_long.c src/check_args.c src/so_long_utils.c src/ft_read.c \
		src/check_valid_path.c src/cal_size.c
OBJ = ${SRCS:.c=.o}

%.o: %.c
	cc ${CFLAGS} ${HEADERS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJ}
	@cmake ${LIBMLX} -B ${LIBMLX}/build ${DEBUG_FLAG}
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
