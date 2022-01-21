/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:30:33 by jrossett          #+#    #+#             */
/*   Updated: 2022/01/21 15:13:16 by jrossett         ###   ########.fr       */
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
t_list	*ft_lstnew(int content);
void	aff_stack(t_list *stack_a);
void	ft_swap(t_list **stack);
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_pa(t_list **stack_a, t_list **stack_b);
t_list	*stack_create(int ac, char **av);
int		ft_atoi(const char *nptr);
t_list	*ft_pop(t_list **stack_a);
void	ft_putstr(char *s);
void	ft_error(void);

#endif