/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:06:02 by jrossett          #+#    #+#             */
/*   Updated: 2022/02/01 12:12:38 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_start(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = lstsize(stack_a);
	while (5 < i--)
		ft_push(stack_b, stack_a, "pb\n");
	ft_five(stack_a, stack_b);
}

void	ft_push_usual(t_list **stack_a, t_list **sb)
{
	t_list	*prev;
	t_list	*after;
	int		index;

	prev = *stack_a;
	after = (*stack_a)->next;
	while (after)
	{
		if ((*sb)->nbr > prev->nbr && (*sb)->nbr < after->nbr)
		{
			index = find_index_cost(stack_a, after);
			ft_top_lowcost(stack_a, index, 'a');
			return ;
		}
		after = after->next;
		prev = prev->next;
		if (after == NULL)
			after = *stack_a;
	}
}

void	ft_push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*max;
	int		nbr;
	int		index;

	nbr = (*stack_b)->nbr;
	max = *stack_a;
	if (nbr > max_nbr(stack_a))
	{
		while (max->nbr != max_nbr(stack_a))
			max = max->next;
		index = find_index_cost(stack_a, max);
		ft_bot_lowcost(stack_a, index, 'a');
	}
	else if (nbr < min_nbr(stack_a))
	{
		while (max->nbr != min_nbr(stack_a))
			max = max->next;
		index = find_index_cost(stack_a, max);
		ft_top_lowcost(stack_a, index, 'a');
	}
	else
		ft_push_usual(stack_a, stack_b);
}

void	big_algo(t_list **stack_a, t_list **stack_b)
{
	t_list	*lowcost;
	t_list	*max;
	int		index;

	ft_start(stack_a, stack_b);
	while (*stack_b)
	{
		lowcost = ft_lowcost(stack_a, stack_b);
		ft_push_lowcost(stack_a, stack_b, lowcost);
	}
	max = *stack_a;
	while (max->nbr != max_nbr(stack_a))
		max = max->next;
	index = find_index_cost(stack_a, max);
	ft_bot_lowcost(stack_a, index, 'a');
}
