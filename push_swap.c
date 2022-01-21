/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:30:27 by jrossett          #+#    #+#             */
/*   Updated: 2022/01/21 15:12:25 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	aff_stack(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		printf("%d -> ", tmp->nbr);
		tmp = tmp->next;
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	//t_list	*stack_b;

	//stack_b = NULL;
	if (ac == 1)
		exit(0);
	ft_check_error(ac, av);
	stack_a = stack_create(ac, av);
	aff_stack(stack_a);
	ft_swap(&stack_a);
	printf("\n");
	aff_stack(stack_a);
	return (0);
}
