#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_atoi(char *str)
{
    int i = 0;
    int res = 0;
    int sig = 1;

    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sig *= -1;
        i++;
    }
    while (str[i] && (str[i] >= '0' && str[i] <= '9'))
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res * sig);
}

int check_int(char **str, int ac)
{
    int j = 1;
    while (j < ac)
    {
        int i = 0;
        if (str[j][i] == '-' || str[j][i] == '+')
            i++;
        while (str[j][i])
        {
            if (str[j][i] < '0' || str[j][i] > '9')
                return 0;
            i++;
        }
        j++;
    }
    return 1;
}

void print_set(int *tab, int size)
{
    int i = 0;
    while (i < size)
    {
        printf("%d ", tab[i]);
        i++;
    }
    printf("\n");
}

void find_subsets(int *tab, int size, int target, int index, int *subset, int subset_size, int current_sum)
{
	if (index == size)
    {
		if (current_sum == target)
			print_set(subset, subset_size);
        return;
    }

    find_subsets(tab, size, target, index + 1, subset, subset_size, current_sum);
	
    subset[subset_size] = tab[index];
    find_subsets(tab, size, target, index + 1, subset, subset_size + 1, current_sum + tab[index]);
}

void powerset(int *tab, int size, int target)
{
    int *subset = malloc(sizeof(int) * size);
    find_subsets(tab, size, target, 0, subset, 0, 0);
    free(subset);
}

int main(int ac, char **av)
{
    if (ac < 3 || !check_int(av, ac))
        return 1;

    int target = ft_atoi(av[1]);
    int n = ac - 2;

    int *tab = malloc(sizeof(int) * n);
    int i = 0;
    while (i < n)
    {
        tab[i] = ft_atoi(av[i + 2]);
        i++;
    }

    powerset(tab, n, target);
    free(tab);
    return 0;
}