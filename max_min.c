/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:16:09 by jrossett          #+#    #+#             */
/*   Updated: 2022/02/08 16:42:47 by teambersaw       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_nbr(t_list **stack)
{
	t_list	*tmp;
	int		min;

	tmp = *stack;
	min = tmp->nbr;
	while (tmp)
	{
		if (tmp->nbr < min)
			min = tmp->nbr;
		tmp = tmp->next;
	}
	return (min);
}

int	max_nbr(t_list **stack)
{
	t_list	*tmp;
	int		max;

	tmp = *stack;
	max = tmp->nbr;
	while (tmp)
	{
		if (tmp->nbr > max)
			max = tmp->nbr;
		tmp = tmp->next;
	}
	return (max);
}

t_list	*ft_cost_pre_push_a(t_list **stack_a, t_list *tmp)
{
	int		nbr;
	t_list	*index;

	nbr = tmp->nbr;
	index = *stack_a;
	if (nbr > max_nbr(stack_a))
	{
		while (index->nbr != max_nbr(stack_a))
			index = index->next;
	}
	else if (nbr < min_nbr(stack_a))
	{
		while (index->nbr != min_nbr(stack_a))
			index = index->next;
	}
	else
		index = ft_cost_pre_usual(stack_a, tmp);
	return (index);
}

t_list	*ft_cost_pre_usual(t_list **stack_a, t_list *tmp)
{
	t_list	*prev;
	t_list	*after;

	prev = *stack_a;
	after = (*stack_a)->next;
	while (after)
	{
		if (tmp->nbr > prev->nbr && tmp->nbr < after->nbr)
		{
			return (after);
		}
		after = after->next;
		prev = prev->next;
		if (after == NULL)
			after = *stack_a;
	}
	return (after);
}

void	ft_norme(int index, int index2, t_list **stack_b, t_list **stack_a)
{
	int	i;

	if (index < index2)
		i = lstsize(stack_b) - index;
	else
		i = lstsize(stack_a) - index2;
	while (i-- > 1)
		ft_rrr(stack_a, stack_b, "rrr\n");
}