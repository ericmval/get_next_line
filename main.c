/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin2 <emartin2@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:38:32 by emartin2          #+#    #+#             */
/*   Updated: 2023/10/13 19:38:43 by emartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"


//read(fd, buffer, BUFFER_SIZE)
int main (void)
{
 //   char *salida;
    int veces = ;
    int i = 0;
    int fd = open ("empty.txt", O_RDONLY);
    char    *ej1 = "1234";
    char    *ej2 = "56789";

    printf ("%s",ft_strjoin(ej1,ej2,0));

    if(fd == -1)
    {
        printf ("error al abrir archivo\n");
        return (-1);
    }

    printf("el fd es %d\n",fd);  
      
    while (i < veces)
    {
        printf ("%s",get_next_line(fd)); 
        i++;
    }
    close (fd);
    return (0);
    
}

