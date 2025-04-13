#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_atoi(char *str)
{
	int i = 0;
	int res = 0;
	int sig = 1;
	if(str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
			sig *= -1;
		i++;
	}
	while(str[i] && (str[i] >= '0' || str[i] <= '9'))
	{
		res *= 10;
		res += (str[i] - 48);
		i++;
	}
	return (res * sig);
}

int check_int(char **str, int ac)
{
	int j = 1;
	if (!str)
		return 0;
	while (j < ac)
	{
		int i = 0;
		while(str[j][i])
		{
			if ((str[j][i] < '0' || str[j][i] > '9'))
				return 0;
			i++;
		}
		j++;
	}
	return 1;
}



int main(int ac, char **av)
{
	if (!check_int(av, ac))
		return 1;
	int i = 1;
	int j = 0;
	int *tab = malloc(sizeof(int) * ac);
	while(i < ac)
	{
		tab[j] = ft_atoi(av[i]);
		i++;
		j++;
	}
}
