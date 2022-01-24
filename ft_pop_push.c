/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:06:11 by jrossett          #+#    #+#             */
/*   Updated: 2022/01/24 12:40:40 by jrossett         ###   ########.fr       */
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

void	lstadd_back(t_list **stack, t_list *tmp)
{
	t_list	*end;

	end = *stack;
	while (end->next)
		end = end->next;
	end->next = tmp;
}

t_list	*ft_pop_bottom(t_list **stack)
{
	t_list	*tmp;
	t_list	*pop;

	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	pop = tmp;
	tmp = *stack;
	while (tmp->next != pop)
		tmp = tmp->next;
	tmp->next = NULL;
	return (pop);
}
