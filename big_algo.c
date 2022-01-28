/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:06:02 by jrossett          #+#    #+#             */
/*   Updated: 2022/01/28 11:34:06 by jrossett         ###   ########.fr       */
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

t_list	*ft_lowcost(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*lowcost;
	int		cost;

	tmp = *stack_b;
	cost = ft_cost(stack_a, tmp);
	lowcost = tmp;
	while (tmp)
	{
		if (cost > ft_cost(stack_a, tmp))
		{
			cost = ft_cost(stack_a, tmp);
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
	while (tmp != lowcost)
	{
		tmp = tmp->next;
		index++;
	}
	return (index);
}

void	ft_push_lowcost(t_list **stack_a, t_list **stack_b, t_list *lowcost)
{
	int	index;

	index = find_index_cost(stack_b, lowcost);
	ft_top_b(stack_b, index);
	while (1 > i--)
		ft_rotate(stack_b, "rb\n");
	
}

void	big_algo(t_list **stack_a, t_list **stack_b)
{
	t_list	*lowcost;

	ft_start(stack_a, stack_b);
	lowcost = ft_lowcost(stack_a, stack_b);
	ft_push_lowcost(stack_a, stack_b, lowcost);
}
