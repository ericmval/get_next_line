#include "get_next_line.h"

char	*new_remain(char *line, char *remain)
{

	int		i;
	char	*new;

	i = 0;
	if (is_nl(line) == 0)
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

char	*new_line(char *line)
{
	int		len;
	int		i;
	char	*new;

	len = 0;
	i = 0;
	if (is_nl(line) == 0)
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

char	*read_file(int fd, int *end)
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
		tmp = ft_strjoin ("",readed,2);
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
    
	if (BUFFER_SIZE <= 0 || fd < 0 )
		return (NULL);
	if (remain)
	line = ft_strjoin("",remain,0);
	else
		line = read_file(fd, &end);
//	if (end == -1)
//		return (NULL);

	while (fd >= 0)
	{
		if (is_nl(line) || end)
		{
			remain = new_remain(line, remain);
			return (new_line(line));
		}
		line = ft_strjoin(line, read_file(fd, &end),3);
//		if (end == -1)
//		{
	//		free (remain);
//			return (NULL);
//		}
	}
	return (NULL);
}













