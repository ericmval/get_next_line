/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin2 <emartin2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:07:07 by emartin2          #+#    #+#             */
/*   Updated: 2023/10/13 20:07:18 by emartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif
#ifndef GET_NEXT_LINE_H
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