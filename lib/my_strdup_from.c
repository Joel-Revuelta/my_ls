/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** my_strdup_from
*/

#include "my.h"

char *my_strdup_from(char const *src, int i)
{
    int j = 0;
    int len = my_strlen(src);

    char *str = malloc(sizeof(char) * (len - i + 1));

    while (src[i] != '\0') {
        str[j] = src[i];
        i++;
        j++;
    }
    str[j] = '\0';
    return (str);
}
