/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:04:10 by jrossett          #+#    #+#             */
/*   Updated: 2022/02/08 16:38:39 by teambersaw       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cost_push_a(t_list **stack_a, t_list *tmp)
{
	int		cost;
	int		nbr;
	t_list	*index;

	cost = 0;
	nbr = tmp->nbr;
	index = *stack_a;
	if (nbr > max_nbr(stack_a))
	{
		while (index->nbr != max_nbr(stack_a))
			index = index->next;
		cost = ft_cost_bot(stack_a, index);
	}
	else if (nbr < min_nbr(stack_a))
	{
		while (index->nbr != min_nbr(stack_a))
			index = index->next;
		cost = ft_cost_top(stack_a, index);
	}
	else
		cost = ft_cost_usual(stack_a, tmp);
	return (cost);
}

int	ft_cost_usual(t_list **stack_a, t_list *tmp)
{
	t_list	*prev;
	t_list	*after;
	int		cost;

	prev = *stack_a;
	after = (*stack_a)->next;
	cost = 0;
	while (after)
	{
		if (tmp->nbr > prev->nbr && tmp->nbr < after->nbr)
		{
			cost = ft_cost_top(stack_a, after);
			return (cost);
		}
		after = after->next;
		prev = prev->next;
		if (after == NULL)
			after = *stack_a;
	}
	return (cost);
}

int	ft_cost_top(t_list **stack_b, t_list *tmp)
{
	int	index;
	int	cost;
	int	i;
	int	j;

	cost = 0;
	index = find_index_cost(stack_b, tmp);
	i = lstsize(stack_b);
	j = i - index + 1;
	if (i == 1)
		return (cost);
	if (i / 2 >= index)
		while (1 < index--)
			cost++;
	else if (i / 2 < index)
		while (j--)
			cost++;
	return (cost);
}

int	ft_cost_bot(t_list **stack, t_list *tmp)
{
	int	index;
	int	cost;
	int	i;
	int	j;

	cost = 0;
	index = find_index_cost(stack, tmp);
	i = lstsize(stack);
	j = i - index + 1;
	if (i == 1)
		return (cost);
	if (i / 2 >= index)
		while (1 <= index--)
			cost++;
	else if (i / 2 < index)
		while (1 < j--)
			cost++;
	return (cost);
}

int	ft_cost(t_list **stack_a, t_list **stack_b, t_list *tmp)
{
	int	cost;

	cost = ft_cost_top(stack_b, tmp) + ft_cost_push_a(stack_a, tmp);
	return (cost);
}
