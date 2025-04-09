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
                i = i - j;
        }
        write(1 ,&str[i], 1);
        i++;
    }
}
int main(int ac, char **av)
{
    char *str = malloc(1);
    char *str2 = malloc(6);
    int bytes_read;
    if (!str)
    {
        perror("Error");
        return 1;
    }
    str[0] = '\0';
    while ((bytes_read = read(0, str2, 5)) > 0)
    {
        str2[bytes_read] = '\0';
        str = ft_join(str, str2);
        if (!str)
            return 1;
    }
    ft_findstr(str, av[1]);
    free(str);
    return 0;
}
