/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkutlu <zkutlu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 22:45:06 by zkutlu            #+#    #+#             */
/*   Updated: 2025/07/29 22:45:07 by zkutlu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    size_t i = 0;
    if (!s)
        return 0;
    while (s[i])
        i++;
    return i;
}

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

	if (!stash)
		return (0);
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