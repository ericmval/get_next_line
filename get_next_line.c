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
	char		*exit_str;
	static char	*midchar;
	int end;
	static int end2;

	end = 0 ;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	exit_str = ft_line (fd,1,&end,midchar,&end2);
	if (exit_str == NULL)
		return NULL;
	if (ft_strchr(exit_str,10) != NULL)
	{
		midchar = ft_postchar(exit_str);
		return(ft_prechar(exit_str));
	}
	else if (ft_strchr(exit_str,10) == NULL && end == 1)
		end2 = 1;
	return (exit_str);
}
char	*ft_postchar(char const *full_line)
{
	char *mid;
	ssize_t n;
	ssize_t i;

	i = 0;
	n = ft_strlen(full_line);
	while (i <= n && (full_line[i] != '\n'))
		i++;
	i++;
	mid = ft_calloc (n -i + 1,1);
	n = 0;
	while (i < (unsigned int)ft_strlen(full_line))
	{
		mid[n] = full_line[i];
		i++;
		n++;
	}
	mid[n] = '\0';
	return (mid);


}
char	*ft_prechar(char const *full_line )
{
	char *mid;
	ssize_t n;
	ssize_t i;

	i = 0;
	n = ft_strlen(full_line);
	while (i < n && (full_line[i] != '\n'))
		i++;
	mid = ft_calloc (i+ 2,1);
	n = 0;
	while (n <= i)
	{
		mid[n] = full_line[n];
		n++;
	}
	mid[n] = '\0';
	return (mid);



}


char *ft_line(int fd, ssize_t reader,int *end ,char *midchar,int *end2)
{
	char	*out_str;
	char	*buffer;

	if (*end2 == 1)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE +1 , 1);
	if (!buffer)
		return (NULL);
	if (!midchar)
		out_str = ft_strjoin("","");
	else
		out_str = ft_strjoin(midchar,"");
	if (!out_str)
		return (free(buffer),NULL); 	
	while (reader  > 0 )
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == 0 && *end == 0)
				return (free(buffer),NULL);
		if (reader < BUFFER_SIZE)
		{
			*end = 1;
			if (reader == 0)
				return (out_str);
//			if (reader == 0 && !(*end))
//				return (free(buffer),NULL);
//			if (reader ==  0 && *end == 0 && midchar)
//				return (ft_prechar(midchar));
		}
		if (reader == -1)
			return (free(out_str),NULL);
		out_str = ft_strjoin(out_str,buffer);
		if (ft_strchr(out_str,10) != NULL)
			return	(out_str);
		if (ft_strchr(buffer, 10) == NULL && *end )
			return (free(buffer),out_str);
	}
	return (out_str);	
}	