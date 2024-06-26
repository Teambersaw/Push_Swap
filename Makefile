# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 14:30:35 by jrossett          #+#    #+#              #
#    Updated: 2022/02/01 22:07:10 by teambersaw       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c push_swap_error.c push_swap_utils.c push_swap_operation.c ft_pop_push.c \
	push_swap_operation2.c little_algo.c big_algo.c ft_cost.c ft_lowcost.c \
	max_min.c

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