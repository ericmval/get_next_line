/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin2 <emartin2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:08:19 by emartin2          #+#    #+#             */
/*   Updated: 2023/10/13 20:08:24 by emartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
 #include "get_next_line.h"
/*
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*exit;
	char	*o_exit;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	exit = (char *) malloc (len + 1);
	if (!exit)
		return (NULL);
	o_exit = exit;
	while (*s1)
	{
		*exit = *s1;
		exit++;
		s1++;
	}
	while (*s2)
	{
		*exit = *s2;
		exit++;
		s2++;
	}
	*exit = '\0';
	return (o_exit);
}
//junta 2 estrings
*/
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}
// nide el largo de un string

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
//reserva memoria y la llena de 000

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

char	*ft_strjoin(char *s1, char *s2,int frenum)
{
	size_t	len;
	char	*exit;
	int		i;
	int		e;

	if (!s1 || !s2)
			return (NULL);
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