
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>


char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2,int frenum);
int		is_nl(char *s);
int		ft_strlen(char *str);
char	*new_line(char *line);
char	*new_remain(char *line, char *remain);
char	*read_file(int fd, int *end);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(const char *s, int c);
#endif
