#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
	ft_putchar('\n');
}

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void	swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort_str(char *str, int len)
{
	int i = 0;
	while (i < len - 1)
	{
		int j = i + 1;
		while (j < len)
		{
			if (str[i] > str[j])
				swap(&str[i], &str[j]);
			j++;
		}
		i++;
	}
}

// Find next lexicographical permutation
int	next_perm(char *str, int len)
{
	int i = len - 2;

	while (i >= 0 && str[i] >= str[i + 1])
		i--;

	if (i < 0)
		return (0); // last permutation

	int j = len - 1;
	while (str[j] <= str[i])
		j--;

	swap(&str[i], &str[j]);

	int start = i + 1;
	int end = len - 1;

	while (start < end)
	{
		swap(&str[start], &str[end]);
		start++;
		end--;
	}
	return (1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	int len = ft_strlen(av[1]);
	char *perm = malloc(len + 1);
	if (!perm)
		return (1);
	
	int i = 0;
	while (i < len)
	{
		perm[i] = av[1][i];
		i++;
	}
	perm[i] = '\0';

	sort_str(perm, len);
	ft_putstr(perm);

	while (next_perm(perm, len))
		ft_putstr(perm);

	free(perm);
	return (0);
}
