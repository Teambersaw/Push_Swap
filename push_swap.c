/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:30:27 by jrossett          #+#    #+#             */
/*   Updated: 2022/02/01 17:02:37 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list *stack)
{
	t_list	*tmp;
	t_list	*v;

	tmp = stack;
	while (tmp)
	{
		v = tmp->next;
		free(tmp);
		tmp = v;
	}
	stack = NULL;
}

int	ft_sorted(t_list **stack)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *stack;
	prev = tmp;
	while (tmp)
	{
		if (prev->nbr > tmp->nbr)
			return (0);
		prev = tmp;
		tmp = tmp->next;
	}
	return (1);
}

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new -> nbr = content;
	new -> next = NULL;
	return (new);
}

t_list	*stack_create(int ac, char **av)
{
	t_list	*tmp;
	t_list	*stack_a;

	stack_a = NULL;
	while (ac > 1)
	{
		tmp = ft_lstnew(ft_atoi(av[--ac]));
		lstadd_front(&stack_a, tmp);
	}
	return (stack_a);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	if (ac == 1)
		exit(0);
	ft_check_error(ac, av);
	stack_a = stack_create(ac, av);
	little_algo(&stack_a, &stack_b);
	big_algo(&stack_a, &stack_b);
	free_stack(stack_a);
	stack_b = NULL;
	return (0);
}
