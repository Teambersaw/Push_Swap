/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:30:33 by jrossett          #+#    #+#             */
/*   Updated: 2022/01/24 15:43:45 by jrossett         ###   ########.fr       */
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
t_list	*stack_create(int ac, char **av);
void	lstadd_front(t_list **stack, t_list *tmp);
void	ft_jules(void);
void	lstadd_back(t_list **stack, t_list *tmp);
t_list	*ft_lstnew(int content);
void	aff_stack(t_list *stack_a);

void	ft_swap(t_list **stack, char *str);
void	ft_ss(t_list **stack_a, t_list **stack_b, char *str);
void	ft_p(t_list **stack_a, t_list **stack_b, char *str);
void	ft_rrr(t_list **stack_a, t_list **stack_b, char *str);
void	ft_r(t_list **stack, char *str);
void	ft_r2(t_list **stack_a, t_list **stack_b, char *str);
void	ft_rr(t_list **stack, char *str);

int		ft_atoi(const char *nptr);
t_list	*ft_pop(t_list **stack_a);
t_list	*ft_pop_bottom(t_list **stack);
void	ft_putstr(char *s);
void	ft_error(void);

#endif