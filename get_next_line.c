#include <stdlib.h>
#include <unistd.h>

// Eksik fonksiyon prototipleri ve makrolar
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

size_t  ft_strlen(const char *s)
{
    size_t i = 0;
    if (!s)
        return 0;
    while (s[i])
        i++;
    return i;
}

char    *ft_strdup(const char *s)
{
    size_t len = ft_strlen(s);
    char *dup = malloc(len + 1);
    if (!dup)
        return NULL;
    for (size_t i = 0; i < len; i++)
        dup[i] = s[i];
    dup[len] = '\0';
    return dup;
}

// ft_strjoin fonksiyonu
char *ft_strjoin(char *s1 ,char *s2)
{
    size_t  i = 0;
    size_t  j = 0;
    char    *str;

    if (!s1 && !s2)
        return (NULL);
    str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!str)
        return (NULL);
    while (s1 && s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    while (s2 && s2[j])
    {
        str[i + j] = s2[j];
        j++;
    }
    str[i + j] = '\0';
    free(s1); // s1'i free'le, aksi halde memory leak olur
    return (str);
}

// ft_substr fonksiyonu
char *ft_substr(char *stash, int start, int len)
{
    char *substr;
    int i  = 0;
    int j = 0;

    if(!stash || start >= (int)ft_strlen(stash))
        return (ft_strdup(""));
    if(len > (int)ft_strlen(stash) - start)
        len = ft_strlen(stash) - start;
    substr = malloc(sizeof(char)*(len + 1));
    if(!substr)
        return NULL;

    i = start;
    while(j < len && stash[i])
    {
        substr[j] = stash[i];
        i++;
        j++;
    }
    substr[j] = '\0';
    return substr;
}

// ft_strchar fonksiyonu
char *ft_strchar(const char *s,char c)
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

// get_line fonksiyonu
char *get_line(char *stash)
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

// trim_stash fonksiyonu
char *trim_stash(char *stash)
{
    int i = 0;
    char *new_stash;

    while(stash[i] && stash[i] != '\n')
        i++;
    if (!stash[i]) // newline yoksa
    {
        free(stash);
        return NULL;
    }
    new_stash = ft_substr(stash, i+1, ft_strlen(stash) - i - 1);
    free(stash);
    return new_stash;
}

// get_next_line fonksiyonu
char *get_next_line(int fd)
{
    char *buffer;
    static char *stash = NULL;
    int bytes_read;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return NULL;
    bytes_read = 1;
    while (!ft_strchar(stash, '\n') && (bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes_read] = '\0';
        stash = ft_strjoin(stash, buffer);
    }
    free(buffer);
    if (!stash || !stash[0])
        return NULL;
    line = get_line(stash);
    stash = trim_stash(stash);
    return line;
}

// extract_lineif fonksiyonu (kullanılmıyor, isterseniz silebilirsiniz)
char *extract_lineif(char **stash)
{
    char *newline;
    int len;
    char *line;

    newline = ft_strchar(*stash, '\n');
    if (newline)
        len = newline - *stash + 1;
    else
        len = ft_strlen(*stash);
    line = ft_substr(*stash, 0, len);
    if(!line)
        return NULL;
    return line;
}

