# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 14:30:35 by jrossett          #+#    #+#              #
#    Updated: 2022/01/24 14:43:01 by jrossett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
DIR_OBJS=objs/
SRCS=push_swap.c push_swap_error.c push_swap_utils.c push_swap_operation.c ft_pop_push.c \
	push_swap_operation2.c
OBJS=$(patsubst %.c, $(DIR_OBJS)%.o, $(SRCS))
NAME=push_swap

$(DIR_OBJS)%.o: ./%.c
	$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re