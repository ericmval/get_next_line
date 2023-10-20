/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin2 <emartin2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:07:51 by emartin2          #+#    #+#             */
/*   Updated: 2023/10/13 20:07:55 by emartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		inchar[BUFFER_SIZE + 1];
	char		*exit_str;
	static char	midchar[BUFFER_SIZE + 1];
	static int end;
	ssize_t reader;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	reader = 1;
	while (reader  > 0)
	{
		reader = read(fd, inchar, BUFFER_SIZE);
		if (reader == 0)
			break;
		if (reader < BUFFER_SIZE)
			end = 1;
		if (reader == -1)
		{
			if (exit_str)
				free(exit_str);
			return (NULL);
		}
//		inchar[BUFFER_SIZE] = '\0';
		if (ft_strchr(inchar, 10) != NULL)
			return (ft_strjoin(exit_str, ft_sep(inchar, &midchar,
						0)));
		exit_str = ft_strjoin(exit_str, inchar);
	}	
	if (ft_strlen(midchar) > 0 && ft_strchr(midchar, 10) != NULL && end)
		return (ft_sep(midchar, &midchar, 0));
	else if (ft_strlen(midchar) > 0 && ft_strchr(midchar, 10) == NULL && end)
		exit_str = ft_strjoin(midchar, "");
	if (end ==1)
		return (free(exit_str),NULL);
	
	
	return (exit_str);
}

char	*ft_sep(const char *pre, char (*post)[BUFFER_SIZE + 1], ssize_t i)
{
	char	*out;
	ssize_t	e;
	char	mid[BUFFER_SIZE + 1];
	

	e = 0;
	out = ft_calloc(ft_strlen(pre) + 1, sizeof(char));
	ft_bzero(mid, BUFFER_SIZE + 1);
	if (!out)
		return (free(),NULL);
	while (pre[i] != '\n' && pre[i])
	{
		out[i] = pre[i];
		i++;
	}
	out[i] = pre[i];
	while (pre[++i] != '\0')
	{
		mid[e] = pre[i];
		e++;
	}
	ft_bzero(*post, BUFFER_SIZE + 1);
	e = -1;
	while (e++ <= (long)ft_strlen((*post)))
		(*post)[e] = mid[e];
	return (out);
}
