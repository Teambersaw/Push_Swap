#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	unsigned int res;
    int final;
	int	i;
	int	j;
    unsigned int max;

    max = 2147483648;
	i = 0;
	res = 0;
	j = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			j = -1;
		i++;
	}
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		res = res * 10 + (nptr[i] - '0');
        printf("%u\n", res);
		i++;
	}
    if (j == -1)
    {
        if (res > max)
            return (0);
    }
    if (j == 1)
    {
        if (res > max - 1)
            return (0);
    }
    final = res * j;
	return (final);
}

int main(void)
{
    int i;

    i = ft_atoi("2147483647");
    printf("%d", i);
    return (0);
}