/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:15:53 by jrossett          #+#    #+#             */
/*   Updated: 2022/01/24 15:47:13 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack, char *str)
{
	t_list	*push;
	t_list	*push2;

	if (!stack || (*stack)->next == NULL)
		return ;
	push = ft_pop(stack);
	push2 = ft_pop(stack);
	lstadd_front(stack, push);
	lstadd_front(stack, push2);
	ft_putstr(str);
}

void	ft_ss(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!stack_a || (*stack_a)->next == NULL)
		return ;
	if (!stack_b || (*stack_b)->next == NULL)
		return ;
	ft_swap(stack_a, 0);
	ft_swap(stack_b, 0);
	ft_putstr(str);
}

void	ft_p(t_list **stack_a, t_list **stack_b, char *str)
{
	t_list	*push;

	if (!stack_b || !(*stack_b))
		return ;
	push = ft_pop(stack_b);
	lstadd_front(stack_a, push);
	ft_putstr(str);
}

void	ft_rr(t_list **stack, char *str)
{
	t_list	*push;

	push = ft_pop_bottom(stack);
	lstadd_front(stack, push);
	ft_putstr(str);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b, char *str)
{
	ft_rr(stack_a, 0);
	ft_rr(stack_b, 0);
	ft_putstr(str);
}
