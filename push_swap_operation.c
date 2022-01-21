/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:15:53 by jrossett          #+#    #+#             */
/*   Updated: 2022/01/21 15:28:39 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack)
{
	t_list	*push;
	t_list	*push2;

	if (!stack || (*stack)->next == NULL)
		return ;
	push = ft_pop(stack);
	push2 = ft_pop(stack);
	lstadd_front(stack, push);
	lstadd_front(stack, push2);
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || (*stack_a)->next == NULL)
		return ;
	if (!stack_b || (*stack_b)->next == NULL)
		return ;
	ft_swap(stack_a);
	ft_swap(stack_b);
}

//void	ft_p(t_list **stack_a, t_list **stack_b)
//{
//	return ;
//}
