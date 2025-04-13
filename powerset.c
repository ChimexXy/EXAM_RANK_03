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

void print_set(int *tab)
{
	int i = 0;
	while(tab[i])
	{
		printf("%d ", tab[i]);
		i++;
	}
		printf("\n");
}

void powerset(int *tab, int ac)
{
	int i = 1;
	int r = 1;
	int sum = 0;
	while(i < ac)
	{
		int m = i;
		int *set = malloc(sizeof(int) * ac);
		if(tab[m])
		{
		int j = m + 1;
			while(tab[j])
			{
				sum = tab[m] + tab[j];
				set[0] = tab[i];
				set[r] = tab[j];
				if(sum > tab[0])
				{
					// free(set[r]);
					sum -= tab[j];
					// r--;
				}
				if(sum == tab[0])
				{
					print_set(set);
					free(set);
					break;
				}
				r++;
				j++;
			}
		}
		i++;
	}
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
	tab[j] = '\0';
	powerset(tab, ac);
}
