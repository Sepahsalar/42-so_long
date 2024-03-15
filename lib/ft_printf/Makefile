# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 16:56:34 by asohrabi          #+#    #+#              #
#    Updated: 2024/03/15 11:49:31 by asohrabi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FUNC = ft_putnbr.c ft_puthex.c ft_uns_putnbr.c ft_putpoint.c \
		ft_printf.c ft_printf_utils.c \

OBJ = ${FUNC:.c=.o}

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	@cc ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJ}	
	@ar -crs ${NAME} ${OBJ}

clean:
	@rm -f ${OBJ}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all, clean, fclean, re