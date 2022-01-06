# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 14:30:35 by jrossett          #+#    #+#              #
#    Updated: 2022/01/06 15:13:46 by jrossett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c push_swap_error.c push_swap_utils.c \

OBJS = ${SRCS:.c=.o}

NAME = push_swap

${NAME}: ${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re