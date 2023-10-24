#include "get_next_line.h"
char *get_next_line(int fd)
{
    char  *exit_str;
    static char *buffer;
    int    end;
    char    *mid;

    end = 0;
    exit_str = NULL;
    if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
        return (free(exit_str),NULL);
    if (!buffer)
        buffer = (char*) ft_calloc (BUFFER_SIZE +1 ,1);
    exit_str = ft_newline(fd,buffer,&end,BUFFER_SIZE);
    if (!exit_str)
    {
    //    free(buffer);
        return(NULL);
    }
    if (end == 1 && ft_strchr(exit_str, 10 ) == NULL)
    {
        return (exit_str);
    }
    mid = ft_prechar(exit_str);
    buffer = ft_postchar(exit_str);
    return (mid);
 //   return(free(exit_str),mid);
}
char *ft_newline(int fd,char *buffer,int *end,int reader)
{
    char *exit_str;
    
    exit_str = buffer;
//    exit_str = ft_strjoin(buffer, "",0);
    buffer =  ft_calloc (BUFFER_SIZE +1 ,1);
    if (!buffer)
        return(free(exit_str),NULL);
    while (reader == BUFFER_SIZE)
    {
        reader = read(fd,buffer,BUFFER_SIZE);
        if (reader == 0 && ft_strlen(exit_str) == 0)
            return NULL;
        if (*end == 0)
            exit_str = ft_strjoin(exit_str,buffer,1);
        if (ft_strchr(exit_str,10) != NULL)
            return (exit_str);
    }
    *end = 1;
    return (exit_str);
}
char *ft_postchar(char *full_line)
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
char *ft_prechar(char *full_line )
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
// free(full_line);
 return (mid);
}

















