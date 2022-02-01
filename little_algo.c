/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:53:08 by jrossett          #+#    #+#             */
/*   Updated: 2022/02/01 21:56:02 by teambersaw       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	little_algo(t_list	**stack, t_list **stack_b)
{	
	if (lstsize(stack) == 2)
		ft_swap(stack, "sa\n");
	else if (lstsize(stack) == 3)
		ft_three(stack);
	else if (lstsize(stack) == 4)
		ft_four(stack, stack_b);
	else if (lstsize(stack) == 5)
		ft_five(stack, stack_b);
	return ;
}

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

void	ft_five(t_list **stack, t_list **stack_b)
{
	int	i;

	i = ft_min_index(stack);
	if (i == 2)
		ft_swap(stack, "sa\n");
	if (i == 3)
	{
		ft_reverse_rotate(stack, "rra\n");
		ft_reverse_rotate(stack, "rra\n");
		ft_reverse_rotate(stack, "rra\n");
	}
	if (i == 4)
	{
		ft_reverse_rotate(stack, "rra\n");
		ft_reverse_rotate(stack, "rra\n");
	}
	if (i == 5)
		ft_reverse_rotate(stack, "rra\n");
	ft_push(stack_b, stack, "pb\n");
	ft_four(stack, stack_b);
	ft_push(stack, stack_b, "pa\n");
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
}
