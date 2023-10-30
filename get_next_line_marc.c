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
	if(!new)
	{
		free(line);
		return NULL;
	}
	len = 0;
	while (line[len] != '\n')
		new[i++] = line[len++];
	new[i++] = '\n';
	new[i] = 0;
	free(line);
	return (new);
}
// Tiene que llenarme remain, hastq eu almenos haya una linea, o  sea la ultima, o algo a fallado
char	*ft_read_file(int fd, char *remain)
{
	char	*readed;
	int		nb;
	char	*tmp;

	readed = (char *) ft_calloc(BUFFER_SIZE + 1, 1);
	if(!readed)
	{
		free(remain);
		return (NULL);
	}
	nb = 1;
	while(nb > 0  && !ft_is_nl(readed)){
		nb = read(fd, readed, BUFFER_SIZE);
		if (nb == -1){
			free(readed);
			return (true_free(&remain));
		}
		readed[nb] = '\0';
		remain = ft_strjoin(remain, readed);
	}
	free(readed);
	return(remain);
}

char	*get_next_line(int fd)
{
	static char	*remain = NULL;
	char		*line;
	int			end;

	end = 0;
	if (BUFFER_SIZE <= 0 || fd < 0 )
		return (NULL);
	remain = ft_read_file(fd, remain);
	if(!remain)
		return (NULL);
	line = ft_new_line(remain);
	if(!line)
		return (true_free(&remain));
	/*{
		free(remain);
		remain = NULL;
		return (NULL);
	}*/
	remain = ft_new_remain(line, remain);
	return (NULL);
}
char *true_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return NULL;
}


char	*ft_freezer(char *remain, char *line)
{
	if (remain)
		free (remain);
	if (line)
		free (line);
	return (NULL);
}
