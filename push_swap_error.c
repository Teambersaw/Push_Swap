/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:12:58 by teambersaw        #+#    #+#             */
/*   Updated: 2022/01/29 01:59:46 by teambersaw       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	ft_atoi(const char *nptr)
{
	long long	res;
	int			j;

	res = 0;
	j = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			j = -1;
		nptr++;
	}
	while ((*nptr >= '0') && (*nptr <= '9'))
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	if (j == -1)
		if (res > 2147483648)
			ft_error();
	if (res > 2147483647 && j == 1)
		ft_error();
	return ((int) res * j);
}

int	ft_strcmp(char *s1, char *s2)
{
	if (*s1 == '+')
		s1++;
	if (*s2 == '+')
		s2++;
	if (*s1 == '-' && *(s1 + 1) == '0')
		s1++;
	if (*s2 == '-' && *(s2 + 1) == '0')
		s2++;
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (1);
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (1);
	return (0);
}

int	ft_error_check(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 1;
		while (j < i)
		{
			if (!ft_strcmp(av[j], av[i]))
				ft_error ();
			j++;
		}
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j++] > '9')
				ft_error();
		}
		i++;
	}
	return (1);
}

int	ft_check_error(int ac, char **av)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if ((av[i][0] == '-' || av[i][0] == '+') && ft_strlen(av[i]) > 11)
			ft_error();
		if ((av[i][0] != '-' && av[i][0] != '+') && ft_strlen(av[i]) > 10)
			ft_error();
	}
	ft_error_check(ac, av);
	i = 0;
	while (av[++i])
	{
		if (av[i][0] == 0 || (av[i][0] == '0' && ft_strlen(av[i]) > 1))
			ft_error();
		if ((av[i][0] == '+' || av[i][0] == '-') && ft_strlen(av[i]) == 1)
			ft_error();
		if ((av[i][0] == '+' || av[i][0] == '-') && av[i][1] == '0'
			&& ft_strlen(av[i]) > 2)
			ft_error();
		ft_atoi(av[i]);
	}
	return (1);
}
