/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:30:27 by jrossett          #+#    #+#             */
/*   Updated: 2022/01/04 16:42:30 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			j++;
		i++;
	}
	if (j == i)
		return (1);
	return (0);
}

int	ft_error(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 1;
		while (j < i)
		{
			if (ft_strcmp(av[j], av[i]))
				return (0);
			j++;
		}
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	if (ft_error(ac, av) == 0)
	{
		write(2, "error\n", 6);
		return (0);
	}
	return (0);
}
