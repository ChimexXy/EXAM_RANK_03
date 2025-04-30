
#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
		i++;
	return i;
}

int check_av(char *av)
{
    int i = 0;
    if (!av)
        return 0;
    while (av[i])
    {
        if (av[i] != '(' && av[i] != ')')
            return 0;
        i++;
    }
    return 1;
}

int is_matching(char *str)
{
    int count = 0;
    int i = 0;
    while (str[i])
    {
        if (str[i] == '(')
            count++;
        else if (str[i] == ')')
        {
            count--;
            if (count < 0)
                return 0;
        }
        i++;
    }
    if(count == 0)
	{
    	puts(str);
		return 1;
	}
	return 0;
}


void rip(char *str, int pos, int open, int to_remove, char *tmp)
{
	if (!str[pos])
	{
	    if (open == 0 && to_remove == 0)
	    {
	        tmp[pos] = '\0';
	        puts(tmp);
	    }
	    return;
	}
    if (to_remove > 0)
    {
            tmp[pos] = ' ';
            rip(str, pos + 1, open, to_remove - 1, tmp);
    }
    if (str[pos] == '(')
    {
            tmp[pos] = '(';
            rip(str, pos + 1, open + 1, to_remove, tmp);
    }
    else if (str[pos] == ')')
    {
            if (open > 0)
            {
                    tmp[pos] = ')';
                    rip(str, pos + 1, open - 1, to_remove, tmp);
            }
    }
    else
    {
            tmp[pos] = str[pos];
            rip(str, pos + 1, open, to_remove, tmp);
    }
}

int total_removals(char *str)
{
    int open = 0, close = 0;
    for (int i = 0; str[i]; i++)
    {
            if (str[i] == '(')
                    open++;
            else if (str[i] == ')')
            {
                    if (open > 0)
                            open--;
                    else
                            close++;
            }
    }
    return open + close;
}

int main(int ac, char **av)
{
    if (ac != 2 || !check_av(av[1]))
        return 1;
	if (is_matching(av[1]) == 1)
		return 0;
	int size = ft_strlen(av[1]) + 1;
	char tmp[size];
	rip(av[1], 0, 0, total_removals(av[1]), tmp);
    return 0;
}
