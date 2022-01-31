/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:04:10 by jrossett          #+#    #+#             */
/*   Updated: 2022/01/31 15:56:35 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cost_push_a(t_list **stack_a, t_list *tmp)
{
	int		cost;
	int		nbr;

	cost = 0;
	nbr = tmp->nbr;
	if (nbr > max_nbr(stack_a))
		cost = ft_cost_bot(stack_a, tmp);
	else if (nbr < min_nbr(stack_a))
		cost = ft_cost_top(stack_a, tmp);
	else
		cost = ft_cost_usual(stack_a, tmp);
	return (cost);
}

int	ft_cost_usual(t_list **stack_a, t_list *tmp)
{
	t_list	*last;
	int		cost;
	int		nbr;

	last = ft_lstlast(stack_a);
	nbr = tmp->nbr;
	cost = 0;
	if (last->nbr > nbr && (*stack_a)->nbr > nbr)
		return (cost);
	if (last->nbr < nbr && (*stack_a)->nbr < nbr)
		return (cost);
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
