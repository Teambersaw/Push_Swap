#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
	if (*nptr == '-')
	{
		j = -1;
		nptr++;
	}
	while ((*nptr >= '0') && (*nptr <= '9'))
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	if (j == -1)
		if (res > MAX)
			ft_error();
	if (j == 1)
		if (res > MAX - 1)
			ft_error();
	return ((int) res);
}

int main(int ac, char **av)
{
    int i;

	(void) ac;
    i = ft_atoi(av[1]);
    printf("%d", i);
    return (0);
}