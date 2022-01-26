/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:53:08 by jrossett          #+#    #+#             */
/*   Updated: 2022/01/26 16:58:45 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	ft_five(t_list **stack, t_list **stack_b);
//{}

int	ft_min_index(t_list **stack)
{
	t_list	*tmp;
	t_list	*min;
	int		i;

	i = 1;
	min = *stack;
	tmp = (*stack)->next;
	while (tmp)
	{
		if (min->nbr > tmp->nbr)
			min = tmp;
		tmp = tmp->next;
	}
	tmp = *stack;
	while (tmp != min)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_four(t_list **stack, t_list **stack_b)
{
	int	i;

	i = ft_min_index(stack);
	if (i == 2)
		ft_swap(stack, "sa\n");
	if (i == 3)
	{
		ft_reverse_rotate(stack, "rra\n");
		ft_reverse_rotate(stack, "rra\n");
	}
	if (i == 4)
		ft_reverse_rotate(stack, "rra\n");
	ft_push(stack_b, stack, "pb\n");
	ft_three(stack);
	ft_push(stack, stack_b, "pa\n");
	aff_stack(*stack);
}

void	ft_three(t_list **stack)
{
	int	first;
	int	mid;
	int	last;

	while (!ft_sorted(stack))
	{
		first = (*stack)->nbr;
		mid = (*stack)->next->nbr;
		last = (*stack)->next->next->nbr;
		if (first < mid && mid > last)
			ft_reverse_rotate(stack, "rra\n");
		if ((first > mid && mid < last) && first < last)
			ft_swap(stack, "sa\n");
		if ((first > mid && mid < last) && first > last)
			ft_rotate(stack, "ra\n");
		if (first > mid && mid > last)
			ft_rotate(stack, "ra\n");
	}
	aff_stack(*stack);
}
