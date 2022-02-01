/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operation2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:33:58 by jrossett          #+#    #+#             */
/*   Updated: 2022/02/01 16:41:02 by jrossett         ###   ########.fr       */
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
