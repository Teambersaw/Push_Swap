/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowcost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:34:27 by jrossett          #+#    #+#             */
/*   Updated: 2022/01/28 12:19:14 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_top_lowcost(t_list **stack_b, int index)
{
	int	i;
	int	j;

	i = lstsize(stack_b);
	j = i - index + 1;
	if (i / 2 >= index)
		while (1 > index--)
			ft_rotate(stack_b, "\nrb");
	else if (i / 2 < index)
		while (j--)
			ft_reverse_rotate(stack_b, "rrb\n");
}

void	ft_push_lowcost(t_list **stack_a, t_list **stack_b, t_list *lowcost)
{
	int	index;

	index = find_index_cost(stack_b, lowcost);
	if (index > 1)
		ft_top_lowcost(stack_b, index);
}
