/*
** EPITECH PROJECT, 2022
** CPool_07
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int dest_len = my_strlen(dest);

    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return (dest);
}

char *my_strmcat(char const *dest, char const *src)
{
    int i = 0;
    int j = 0;
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);
    char *res = malloc(sizeof(char) * (dest_len + src_len + 1));

    for (int x = 0; x <= dest_len + src_len; x++) {
        res[x] = '\0';
    }
    while (dest[i]) {
        res[i] = dest[i];
        i++;
    }
    while (src[j]) {
        res[i + j] = src[j];
        j++;
    }
    res[i + j] = '\0';
    return (res);
}
