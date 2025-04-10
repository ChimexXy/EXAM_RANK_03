#include "gnl.h"

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return i;
}

int ft_new_len(char *str)
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

int find_new_line(char *str)
{
	int i = 0;
	while(str[i])
	{
		if(str[i] == '\n')
			return 1;
		i++;
	}
	return 0;
}

char *ft_substr(char *str, int s, int e)
{
	char *ret = malloc(e + 1);
	while(s <= e)
	{
		ret[s] = str[s];
		s++;
	}
	ret[s] = '\0';
	return ret;
}

char *ft_strjoin(char *s1, char *s2)
{
	int i = 0;
	int j = 0;

	if (!s1)
		return(ft_substr(s2, 0, ft_strlen(s2)));
	if (!s2)
		return(ft_substr(s1, 0, ft_strlen(s1)));
	char *ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
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

char *read_line(int fd, char *ret)
{
	int r = 1;
	char *buff = malloc(BUFFER_SIZE + 1);

	int i = 0;
	while(r > 0)
	{
		r = read(fd, buff, BUFFER_SIZE);
		buff[r] = '\0';
		ret = ft_strjoin(ret, buff);
		if (!ret)
		{
			free(buff);
			free(ret);
			return NULL;
		}
		if(find_new_line(ret))
			break ;
	}
	free(buff);
	return ret;
}

char *before_new_line(char *str)
{
	int i = ft_new_len(str + 1);
	return (ft_substr(str, 0, i));
}

char *after_new_line(char *str)
{
	int s = ft_new_len(str);
	int e = ft_strlen(str);

	if (str[s] == '\0')
		return NULL;
	return (ft_substr(str, s, e));
}

char *gnl(int fd)
{
	static char *buff;
	char *hold;
	if(fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buff);
		return NULL;
	}
	buff = read_line(fd, buff);
	if(!buff)
		return NULL;
	hold = before_new_line(buff);
	buff = 
	(buff);
	return hold;
}


int main()
{
	int fd;
	int i = 0;
	fd = open("test.txt", O_RDONLY);
	char *str = gnl(fd);
	char *str1 = gnl(fd);
	char *str2 = gnl(fd);
	char *str3 = gnl(fd);
	printf("---> %s\n", str);
	printf("---> %s\n", str1);
	printf("---> %s\n", str2);
	printf("---> %s\n", str3);
	close(fd);
}
