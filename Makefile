# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 15:48:51 by asohrabi          #+#    #+#              #
#    Updated: 2024/03/22 13:07:09 by asohrabi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Wextra -Werror
LIBMLX = lib/MLX42
LIBFT = lib/libft
LIB_BREW = /Users/${USER}/.brew/Cellar/glfw/3.4/lib
LIBFTPRINTF = lib/ft_printf
LIBFT_FLAGS = -L${LIBFT} -L${LIBFTPRINTF} -lft -lftprintf
LMX_FLAGS = -L${LIBMLX}/build -L${LIB_BREW} -lmlx42 -ldl -pthread -lglfw -lm
HEADERS	= -I ./include -I ${LIBMLX}/include
LIBS_FLAGS = ${LIBFT_FLAGS} ${LMX_FLAGS}

SRCS = src/so_long.c src/check_args.c src/so_long_utils.c src/ft_read.c \
		src/check_valid_path.c src/cal_size.c src/create_elements.c src/check_exit.c \
		src/create_instance.c src/press_key.c src/check_collectible.c \

OBJS = ${SRCS:.c=.o}

%.o: %.c
	@cc ${CFLAGS} ${HEADERS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	@cmake ${LIBMLX} -B ${LIBMLX}/build
	@make -C ${LIBMLX}/build -j4
	@make -C ${LIBFT}
	@make -C ${LIBFTPRINTF}
	cc ${OBJS} ${CFLAGS} ${LIBS_FLAGS} ${HEADERS} -o ${NAME}

clean:
	rm -f ${OBJS}
	@make -C ${LIBFT} clean
	@make -C ${LIBFTPRINTF} clean
	@rm -rf ${LIBMLX}/build

fclean: clean
	rm -f ${NAME}
	@make -C ${LIBFT} fclean
	@make -C ${LIBFTPRINTF} fclean

re: fclean all 

.PHONY: all clean fclean re
