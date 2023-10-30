/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin2 <emartin2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:08:19 by emartin2          #+#    #+#             */
/*   Updated: 2023/10/28 13:50:03 by emartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_is_nl(char *s)
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

char	*ft_strjoin(char *s1, char *s2, int frenum)
{
	size_t	len;
	char	*exit;
	int		i;
	int		e;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if(!s1)
			return NULL;
		s1[0] = '\0';
	}
	i = -1;
	len = ft_strlen(s1) + ft_strlen(s2);
	exit = (char *) ft_calloc (len + 1, 1);
	if (!exit)
	{
		free(s1);
		return (NULL);
	}
	while (s1[++i] != '\0')
		exit[i] = s1[i];
	e = -1;
	while (s2[++e] != '\0')
	{
		exit[i] = s2[e];
		i++;
	}
	free(s1);
	return (exit);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			ent;
	unsigned char	*b;
	size_t			i;

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
