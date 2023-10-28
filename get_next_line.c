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

char	*ft_new_remain(char *line, char *remain)
{
	int		i;
	char	*new;

	i = 0;
	if (ft_is_nl(line) == 0)
	{
		free(remain);
		return (NULL);
	}
	while (line[i])
	{
		if (line[i++] == '\n')
			break ;
	}
	if (line[i] == 0)
	{
		free(remain);
		return (0);
	}
	new = ft_strjoin("", line + i, 0);
	free(remain);
	return (new);
}

char	*ft_new_line(char *line)
{
	int		len;
	int		i;
	char	*new;

	len = 0;
	i = 0;
	if (ft_is_nl(line) == 0)
		return (line);
	while (line[len] != '\n')
		len++;
	len++;
	new = (char *) malloc(len + 1);
	len = 0;
	while (line[len] != '\n')
		new[i++] = line[len++];
	new[i++] = '\n';
	new[i] = 0;
	free(line);
	return (new);
}

char	*ft_read_file(int fd, int *end)
{
	char	*readed;
	int		nb;
	char	*tmp;

	readed = (char *) ft_calloc(BUFFER_SIZE + 1, 1);
	nb = read(fd, readed, BUFFER_SIZE);
	if (nb <= 0)
	{
		*end = 1;
		if (nb == -1)
			*end = -1;
		free(readed);
		return (NULL);
	}
	if (nb < BUFFER_SIZE)
	{
		tmp = ft_strjoin ("", readed, 2);
		return (tmp);
	}
	return (readed);
}

char	*get_next_line(int fd)
{
	static char	*remain = NULL;
	char		*line;
	int			end;

	end = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (remain)
		line = ft_strjoin("", remain, 0);
	else
		line = ft_read_file(fd, &end);
	while (fd >= 0)
	{
		if (ft_is_nl(line) || end)
		{
			remain = ft_new_remain(line, remain);
			return (ft_new_line(line));
		}
		line = ft_strjoin(line, ft_read_file(fd, &end), 3);
		if (end == -1)
			return (remain = ft_freezer(remain, line), NULL);
	}
	return (NULL);
}

char	*ft_freezer(char *remain, char *line)
{
	free (remain);
	free (line);
	return (NULL);
}
