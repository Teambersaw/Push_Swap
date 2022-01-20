/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:30:33 by jrossett          #+#    #+#             */
/*   Updated: 2022/01/20 15:04:41 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				nbr;
	struct s_list	*next;
}						t_list;

int		ft_strlen(char	*str);
int		ft_strcmp(char *s1, char *s2);
int		ft_error_check(int ac, char **av);
int		ft_check_error(int ac, char **av);
void	aff_stack(t_list *stack_a);
int		ft_atoi(const char *nptr);
void	ft_error(void);

#endif