/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:30:27 by jrossett          #+#    #+#             */
/*   Updated: 2022/01/26 13:56:00 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	little_algo(t_list	**stack, t_list **stack_b)
{
	if (ft_sorted(stack))
		exit(0);
	if (lstsize(stack) == 2)
	{
		ft_swap(stack, "sa\n");
		exit(0);
	}
	if (lstsize(stack) == 3)
	{
		ft_three(stack);
		exit(0);
	}
	if (lstsize(stack) == 4)
	{
		ft_four(stack, stack_b);
		exit(0);
	}
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

void	aff_stack(t_list *stack)
{
	t_list	*tmp;

	if (!stack)
		return ;
	tmp = stack;
	while (tmp)
	{
		printf("%d -> ", tmp->nbr);
		tmp = tmp->next;
	}
	printf("\n");
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
	aff_stack(stack_a);
	little_algo(&stack_a, &stack_b);
	printf("oui\n");
	return (0);
}
