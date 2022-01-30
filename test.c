/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:10:05 by teambersaw        #+#    #+#             */
/*   Updated: 2022/01/30 21:55:21 by teambersaw       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	// printf("size valeur: %d\n", i);
	// printf("index valeur: %d\n", index);
	// printf("stack b\n");
	// printf("cost valeur: %d\n", cost);