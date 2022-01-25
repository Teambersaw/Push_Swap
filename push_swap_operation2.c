/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operation2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:33:58 by jrossett          #+#    #+#             */
/*   Updated: 2022/01/25 19:22:37 by teambersaw       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **stack, char *str)
{
	t_list	*push;

	push = ft_pop(stack);
	lstadd_back(stack, push);
	ft_putstr(str);
}

void	ft_rr(t_list **stack_a, t_list **stack_b, char *str)
{
	ft_rotate(stack_a, 0);
	ft_rotate(stack_b, 0);
	ft_putstr(str);
}
