#include "get_next_line.h"

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return i;
}

int find_new_line(char *str)
{
    int i = 0;
    while(str[i])
    {
        if(str[i] == '\n')
            return 0;
        i++;
    }
    return 1;
}

int count_new_line(char *str)
{
    int i = 0;
    while(str[i])
    {
        if(str[i] == '\n')
            return i;
        i++;
    }
    return i;
}

char *ft_strdup(char *str)
{
    int i = 0;
    char *ret = malloc(ft_strlen(str) + 1);
    if(!ret)
        return NULL;
    while(str[i])
    {
        ret[i] = str[i];
        i++;
    }
	ret[i] = '\0';
    return ret;
}
char *ft_substr(char *str, int s, int e)
{
    int i = 0;
    char *ret = malloc(e - s + 1);
    if(!ret || !str)
    {
        free(ret);
        return NULL;
    }
    while(s < e)
    {
        ret[i] = str[s];
        s++;
        i++;
    }
    ret[i] = '\0';
    return ret;
}

char *ft_strjoin(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    if(!s1)
        return (ft_strdup(s2));
    if(!s2)
        return (ft_strdup(s1));
    char *ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if(!ret)
        return NULL;
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
    return (ret);
}


char *read_line(int fd, char *hold)
{
    int r = 1;
    char *buff = malloc(BUFFER_SIZE + 1);
    if(!buff)
    {
        free(buff);
        return NULL;
    }
    while(r > 0)
    {
        r = read(fd, buff, BUFFER_SIZE);
        buff[r] = '\0';
        hold = ft_strjoin(hold, buff);
        if (!hold)
        {
            free(buff);
            return NULL;
        }
        if(!find_new_line(hold))
            break;
    }
    free(buff);
    return hold;
}

char *before_new_line(char *buff)
{
    if(buff[0] == '\0')
    {
        free (buff);
        return NULL;
    }
    int e = count_new_line(buff);
    return (ft_substr(buff, 0, e + 1));
}

char *after_new_line(char *buff)
{
    if(buff[0] == '\0')
        return NULL;
    int s = count_new_line(buff);
    int e = ft_strlen(buff);
	char *str = ft_substr(buff, s + 1, e + 1);
    return (free(buff), str);
}

char    *get_next_line(int fd)
{
    static char *hold;
    char *buff;
    if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    {
        free (hold);
		hold = NULL;
        return NULL;
    }
    hold = read_line(fd, hold);
    if (hold == '\0')
    {
        free(hold);
		hold = NULL;
        return NULL;
    }
    buff = before_new_line(hold);
    hold = after_new_line(hold);
    return (buff);
}
