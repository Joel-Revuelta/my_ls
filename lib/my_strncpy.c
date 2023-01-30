/*
** EPITECH PROJECT, 2022
** CPool_06
** File description:
** my_strncpy
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int len = my_strlen(src);

    while (i < n && i < len) {
        dest[i] = src[i];
        i++;
    }
    if (n > len)
        dest[i] = '\0';
    return (dest);
}
