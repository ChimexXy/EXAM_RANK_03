#include <unistd.h>
#include <stdio.h>

void ft_putstr(char *str)
{
    int i = 0;
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
}

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return i;
}

int check_av(char *av)
{
    int i = 0;
    if(!av)
        return 0;
    while(av[i])
    {
        if(av[i] != '(' || av[i] != ')')
            return 0;
        i++;
    }
    return 1;
}

int count_o_c(char *str)
{
    int o = 0;
    int c = 0;
    int i =0;
    while(str[i])
    {
        if(str[i] == '(')
            o++;
        if(str[i] == ')')
            c++;
        i++;
    }
    if(o == c)
        return o;
    return -1;
}


int matching(char *out)
{
    int i = 0;
    int x = 0;
    while(out[i])
    {
        int j = i + 1;
        while(out[j] && out[i] == '(')
        {
            if(out[i] == '(' && out[j] == ')')
            {
                x++;
                break;
            }
            j++;
        }
        i++;
    }
    int y = count_o_c(out);
    printf("%d\n", y);
    printf("%d\n", x);
    if(x == y)
        ft_putstr(out);
    return 1;
}

int main(int ac, char **av)
{
    if (ac != 2 || check_av(av[1]))
    {
        ft_putstr("error");
        return 1;
    }
    if(!matching(av[1]))
        ft_putstr(av[1]);   
    // int i = 0;
    // int size = ft_strlen(av[1]);
    
}
