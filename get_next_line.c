/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin2 <emartin2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:07:51 by emartin2          #+#    #+#             */
/*   Updated: 2023/11/01 00:08:02 by emartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_freemarc(char **str)
{
	free (*str);
	*str = NULL;
	return (NULL);
}

char	*ft_read_file(int fd, char *buff)
{
	char	*buffer;
	int		reader;

	buffer = ft_calloc(BUFFER_SIZE + 1 , 1);
	if (!buffer)
		return (ft_freemarc(&buff));
	reader = 1;
	while (!ft_is_nl(buffer) && reader != 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buffer);
			return (ft_freemarc(&buff));
		}
		if (reader > 0)
		{
			buffer[reader] = '\0';
			buff = ft_strjoin(buff, buffer);
		}
	}
	free(buffer);
	return (buff);
}
char	*ft_prestr(char *s1, char c)
{
	int		i;
	char	*out;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i] != '\0' && s1[i] != c)
		i++;
	if (s1[i] != '\0')
		i++;
	out = malloc(sizeof(char) * (i + 1));
	if (!out)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0' && s1[i] != c)
		out[i] = s1[i];
	if (s1[i] == c)
	{
		out[i] = s1[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}
char	*ft_poststr(char *buff)
{
	int		i;
	int		e;
	char	*reminder;

	i = 0;
	e = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (!buff[i])
		return (ft_freemarc(&buff));
	reminder = ft_calloc((ft_strlen(buff) - i + 1) ,1 );
	if (!reminder)
		return (ft_freemarc(&buff));
	while (buff[++i] != '\0')
		reminder[e++] = buff[i];
	if (e == 0)
	{
		free(reminder);
		return (ft_freemarc(&buff));
	}
	ft_freemarc(&buff);
	return (reminder);
}

char	*get_next_line(int fd)
{
	static char	*buff = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = ft_read_file(fd, buff);
	if (!buff)
		return (NULL);
	line = ft_prestr(buff, '\n');
	if (!line)
		return (ft_freemarc(&buff));
	buff = ft_poststr(buff);
	return (line);
}
