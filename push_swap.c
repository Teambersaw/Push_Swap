/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:30:27 by jrossett          #+#    #+#             */
/*   Updated: 2022/01/19 15:47:12 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(size_t));
	if (!new)
		return (NULL);
	new -> nbr = content;
	new -> next = NULL;
	return (new);
}

/*void	*lstadd_front(t_list *stack_a)
{
	stack_a =
}*/

void	stack_create(int ac, char **av)
{
	t_list	*stack_a;

	while (ac > 0)
	{
		stack_a = ft_lstnew(ft_atoi(av[--ac]));
		stack_a -> next = stack_a;
	}
	while (stack_a -> next)
	{
		printf("%d\n", stack_a -> nbr);
		stack_a = stack_a -> next;
	}
}

int	main(int ac, char **av)
{
	if (ac == 1)
		exit(0);
	ft_check_error(ac, av);
	stack_create(ac, av);
	return (0);
}
