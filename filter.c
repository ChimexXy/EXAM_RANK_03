
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int ft_len(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return (i);
}

char *ft_join(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    char *ret = malloc(ft_len(s1) + ft_len(s2) + 1);
	if (!ret)
	{
		free(ret);
		return NULL;
	}
    while(s1[i])
    {
        ret[i] = s1[i];
        i++;
    }
    while(s2[j])
    {
        ret[i] = s2[j];
        i++;
        j++;
    }
    ret[i] = '\0';
    free(s1);
    return ret;
}

void ft_putnajm(char *str)
{
    int i = 0;
    while(str[i])
    {
        write(1, "*", 1);
        i++;
    }
}

void    ft_findstr(char *str, char *av)
{
    int i = 0;
    int j = 0;
    while(str[i])
    {
        j = 0;
        if(str[i] == av[j])
        {
            while(str[i] == av[j])
            {
                j++;
                i++;
            }
            if (av[j] == '\0')
                ft_putnajm(av);
            else
			{
                i = i - j;
        		write(1 ,&str[i], 1);
				i++;
			}
        }
		else
		{
        	write(1 ,&str[i], 1);
        	i++;
		}
    }
}
int main(int ac, char **av)
{
	if (ac != 2 || av[1][0] == '\0')
		return 1;
	char *buff = malloc(2);
	char *join = malloc(1);

	if(!buff || !join)
	{
		write(2, "Error\n", 6);
		free (buff);
		free (join);
		return 1;
	}
	int r;
	join[0] = '\0';
	while ((r = read(0, buff, 1)) > 0)
	{
		buff[r] = '\0';
		join = ft_join(join, buff);
		if(!join)
		{
			write(2, "Error\n", 6);
			free (buff);
			free (join);
			return 1;
		}
	}
	if(r == -1)
	{
		write(2, "Error\n", 6);
		free (buff);
		free (join);
		return 1;
	}
	ft_findstr(join, av[1]);
	free (join);
	free (buff);
	return 1;
}
