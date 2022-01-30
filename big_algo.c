/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:06:02 by jrossett          #+#    #+#             */
/*   Updated: 2022/01/30 21:57:46 by teambersaw       ###   ########.fr       */
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

void	big_algo(t_list **stack_a, t_list **stack_b)
{
	t_list	*lowcost;

	ft_start(stack_a, stack_b);
	while (*stack_b)
	{
		lowcost = ft_lowcost(stack_a, stack_b);
		ft_push_lowcost(stack_a, stack_b, lowcost);
	}
}
