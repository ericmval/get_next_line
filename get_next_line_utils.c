
#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (*str++)
		len++;
	return (len);
}
/*
char	*ft_strdup(char *src)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	dest = (char *) malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
*/
/*
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		total;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s2 == NULL)
		return (s1);
	total = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *) malloc(total * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	free(s1);
	free(s2);
	return (str);
}
*/
int	is_nl(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2,int frenum)
{
	size_t	len;
	char	*exit;
	int		i;
	int		e;

	if (!s2)
			return (s1);
	i = -1;
	len = ft_strlen(s1) + ft_strlen(s2);
	exit = (char *) ft_calloc (len + 1,1);
	if (!exit)
		return (NULL);
	while (s1[++i] != '\0')
			exit[i] = s1[i];
	e = -1;
	while (s2[++e] != '\0')
	{
		exit[i] = s2[e];
		i++;
	}
	if (frenum == 1 || frenum == 3)
		free(s1);
	if (frenum == 2 || frenum == 3)
		free(s2);
	return (exit);
}
/*
char	*ft_strchr(const char *s, int c)
{
	char	*exit;

	c = (char) c;
	exit = (char *) s;
	while (*exit != '\0')
	{
		if (*exit == c)
			return (exit);
		exit++;
	}
	if (c == '\0')
		return (exit);
	return (NULL);
}
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			ent;
	unsigned char	*b;
    size_t          i;

    i = 0;
	ent = nmemb * size;
	b = (unsigned char *) malloc(ent);
	if (!b)
		return (NULL);
    while (i < ent)
    {
        b[i] = '\0';
        i++;
    }
	return ((void *) b);
}

