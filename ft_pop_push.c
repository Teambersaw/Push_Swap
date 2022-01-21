/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:06:11 by jrossett          #+#    #+#             */
/*   Updated: 2022/01/21 15:25:44 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_pop(t_list **stack)
{
	t_list	*pop;

	pop = *stack;
	*stack = (*stack)->next;
	pop->next = NULL;
	return (pop);
}

void	lstadd_front(t_list **stack, t_list *tmp)
{
	tmp -> next = *stack;
	*stack = tmp;
}
