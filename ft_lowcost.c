/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowcost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:34:27 by jrossett          #+#    #+#             */
/*   Updated: 2022/02/08 16:44:55 by teambersaw       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lowcost(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*lowcost;
	int		cost;

	tmp = *stack_b;
	cost = ft_cost(stack_a, stack_b, tmp);
	lowcost = tmp;
	while (tmp)
	{
		if (cost > ft_cost(stack_a, stack_b, tmp))
		{
			cost = ft_cost(stack_a, stack_b, tmp);
			lowcost = tmp;
		}
		tmp = tmp->next;
	}
	return (lowcost);
}

int	find_index_cost(t_list	**stack_b, t_list *lowcost)
{
	t_list	*tmp;
	int		index;

	tmp = *stack_b;
	index = 1;
	while (tmp)
	{
		if (tmp == lowcost)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (0);
}

void	ft_top_lowcost(t_list **stack, int index, char c)
{
	int	size;
	int	j;

	size = lstsize(stack);
	j = size - index + 1;
	if (size / 2 >= index)
	{
		while (1 < index--)
		{
			if (c == 'a')
				ft_rotate(stack, "ra\n");
			else
				ft_rotate(stack, "rb\n");
		}
	}
	else if (size / 2 < index)
	{
		while (j--)
		{
			if (c == 'a')
				ft_reverse_rotate(stack, "rra\n");
			else
				ft_reverse_rotate(stack, "rrb\n");
		}
	}
}

void	ft_bot_lowcost(t_list **stack, int index, char c)
{
	int	size;
	int	j;

	size = lstsize(stack);
	j = size - index + 1;
	if (size / 2 >= index)
	{
		while (1 <= index--)
		{
			if (c == 'a')
				ft_rotate(stack, "ra\n");
			else
				ft_rotate(stack, "rb\n");
		}
	}
	else if (size / 2 < index)
	{
		while (1 < j--)
		{
			if (c == 'a')
				ft_reverse_rotate(stack, "rra\n");
			else
				ft_reverse_rotate(stack, "rrb\n");
		}
	}
}

void	ft_push_lowcost(t_list **stack_a, t_list **stack_b, t_list *lowcost)
{
	int	index;
	int	index2;
	int	i;
	t_list *lowa;

	index = find_index_cost(stack_b, lowcost);
	lowa = ft_cost_pre_push_a(stack_a, lowcost);
	index2 = find_index_cost(stack_a, lowa);
	if (index < index2)
		i = index;
	else
		i = index2;
	if (index > lstsize(stack_b) / 2 && index2 > lstsize(stack_a) / 2)
		ft_norme(index, index2, stack_b, stack_a);
	else if (index <= lstsize(stack_b) / 2 && index2 <= lstsize(stack_a) / 2)
		while (i-- > 1)
			ft_rr(stack_a, stack_b, "rr\n");
	index = find_index_cost(stack_b, lowcost);
	if (index > 1)
		ft_top_lowcost(stack_b, index, 'b');
	ft_push_a(stack_a, stack_b);
	ft_push(stack_a, stack_b, "pa\n");
}
