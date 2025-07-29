/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkutlu <zkutlu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 22:45:01 by zkutlu            #+#    #+#             */
/*   Updated: 2025/07/29 22:45:01 by zkutlu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_strchar(const char *s,char c)
{
    int i = 0;
    if(!s)
        return NULL;
    while(s[i])
    {
        if(s[i] == c)
            return (char *)&s[i];
        i++;
    }
    if(c == '\0')
        return (char *)&s[i];
    return NULL;
}

static char *get_line(char *stash)
{
    int i = 0;
    char *line;

    if(!stash || !stash[0])
        return NULL;
    while(stash[i] && stash[i] != '\n')
        i++;
    if(stash[i] == '\n')
        i++;
    line = ft_substr(stash, 0, i);
    return line;
}

char    *ft_read(char *stash, int fd)
{
    char *buffer;
    int bytes_read;

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return NULL;
    bytes_read = 1;
    while (!ft_strchar(stash, '\n') &&  bytes_read != 0)
    {
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read < 0)
    {
        free(stash);
        free(buffer);
        return (NULL);
    }
    buffer[bytes_read] = '\0';
    stash = ft_strjoin(stash, buffer);
    }
    free(buffer);
    return (stash);
}
static char *get_next_line(int fd)
{
    static char *stash = NULL;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    stash = ft_read(stash, fd);
    if (!stash)
        return (NULL);
    line = get_line(stash);
    stash = trim_stash(stash);
    return line;
    
}

//#include <stdio.h>
//#include <fcntl.h>
//#include <stdlib.h>

//int main()
//{
//    int fd = open("a.txt", O_RDWR);
//	char *str = get_next_line(fd);
//	char **tmp;
//	tmp = malloc(sizeof(char *) * 20);
//	int i = 0;
//	while (i < 5)
//	{
//		tmp[i] = malloc(sizeof(char) * 100);
//		i++;
//	}
//	tmp[i] = NULL;
//	i = 0;
//	while (str != NULL)
//	{
//		str = get_next_line(fd);
//		tmp[i] = str;
//		i++;
//	}
//	printf("%d\n", i);
//	printf("%s", tmp[i - 3]);
//}
