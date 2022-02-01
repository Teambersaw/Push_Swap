/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:06:02 by jrossett          #+#    #+#             */
/*   Updated: 2022/02/01 16:42:03 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_mediane(t_list **stack_a, t_list **stack_b, int mediane)
{
	int		size;

	size = lstsize(stack_a) / 2;
	while (lstsize(stack_b) != size)
	{
		if ((*stack_a)->nbr > mediane)
			ft_push(stack_b, stack_a, "pb\n");
		else
			ft_rotate(stack_a, "ra\n");
	}
	while ((*stack_a)->next->next)
		ft_push(stack_b, stack_a, "pb\n");
	if ((*stack_a)->nbr > (*stack_a)->next->nbr)
		ft_swap(stack_a, "sa\n");
}

int	ft_mediane(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*parse;
	int		index;

	tmp = *stack_a;
	while (tmp)
	{
		index = 0;
		parse = *stack_a;
		while (parse)
		{
			if (parse->nbr > tmp->nbr)
				index++;
			parse = parse->next;
		}
		if (index == lstsize(stack_a) / 2)
			return (tmp->nbr);
		tmp = tmp->next;
	}
	return (tmp->nbr);
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
	int		mediane;
	int		index;

	mediane = ft_mediane(stack_a);
	ft_push_mediane(stack_a, stack_b, mediane);
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
