/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:30:33 by jrossett          #+#    #+#             */
/*   Updated: 2022/01/31 15:28:33 by jrossett         ###   ########.fr       */
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

void	ft_putstr(char *s);
int		ft_strlen(char	*str);
int		lstsize(t_list **stack);
t_list	*ft_lstlast(t_list *lst);

void	ft_error(void);
int		ft_atoi(const char *nptr);
int		ft_error_check(int ac, char **av);
int		ft_check_error(int ac, char **av);
int		ft_strcmp(char *s1, char *s2);

int		ft_sorted(t_list **stack);
t_list	*ft_lstnew(int content);
t_list	*stack_create(int ac, char **av);

t_list	*ft_pop(t_list **stack_a);
t_list	*ft_pop_bottom(t_list **stack);
void	lstadd_front(t_list **stack, t_list *tmp);
void	lstadd_back(t_list **stack, t_list *tmp);

void	ft_swap(t_list **stack, char *str);
void	ft_ss(t_list **stack_a, t_list **stack_b, char *str);
void	ft_push(t_list **stack_a, t_list **stack_b, char *str);
void	ft_rotate(t_list **stack, char *str);
void	ft_rr(t_list **stack_a, t_list **stack_b, char *str);
void	ft_reverse_rotate(t_list **stack, char *str);
void	ft_rrr(t_list **stack_a, t_list **stack_b, char *str);

int		ft_min_index(t_list **stack);
void	ft_three(t_list **stack);
void	ft_four(t_list **stack, t_list **stack_b);
void	ft_five(t_list **stack, t_list **stack_b);
void	little_algo(t_list	**stack, t_list **stack_b);

void	big_algo(t_list **stack_a, t_list **stack_b);
void	ft_start(t_list **stack_a, t_list **stack_b);


t_list	*ft_lowcost(t_list **stack_a, t_list **stack_b);
int		find_index_cost(t_list	**stack_b, t_list	*lowcost);
void	ft_push_lowcost(t_list **stack_a, t_list **stack_b, t_list *lowcost);
void	ft_top_lowcost(t_list **stack_b, int index);

int		ft_cost(t_list **stack_a, t_list **stack_b, t_list *tmp);
int		ft_cost_top(t_list **stack_b, t_list *tmp);
int		ft_cost_bot(t_list **stack, t_list *tmp);
int		ft_cost_push_a(t_list **stack_a, t_list *tmp);
int		ft_cost_usual(t_list **stack_a, t_list *tmp);

int		max_nbr(t_list **stack);
int		min_nbr(t_list **stack);

void	aff_stack(t_list *stack_a);

#endif