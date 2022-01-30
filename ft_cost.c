/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:04:10 by jrossett          #+#    #+#             */
/*   Updated: 2022/01/30 22:19:13 by teambersaw       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cost_push_a(t_list **stack_a, t_list *tmp)
{
	int	cost;
	int	nbr;

	nbr = tmp->nbr;	
	return (cost);
}
int	ft_cost_top_b(t_list **stack_b, t_list *tmp)
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
	{
		while (1 < index--)
			cost++;	
	}
	else if (i / 2 < index)
	{
		while (j--)
			cost++;
	}
	return (cost);
}

int	ft_cost(t_list **stack_a, t_list **stack_b, t_list *tmp)
{
	int	cost;

	cost = ft_cost_top_b(stack_b, tmp) + ft_cost_push_a(stack_a, tmp);
	return (cost);
}
