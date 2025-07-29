#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <stdio.h>

# include <stdlib.h>
# include <unistd.h>
// Eksik fonksiyon prototipleri ve makrolar
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

size_t  ft_strlen(const char *s);
char *ft_strjoin(char *s1 ,char *s2);
char *ft_substr(char *stash, int start, int len);
char *trim_stash(char *stash);

#endif