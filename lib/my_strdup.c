/*
** EPITECH PROJECT, 2022
** CPool_05
** File description:
** my_compute_power_rec
*/

#include "my.h"

char *my_strdup(char const *src)
{
    int i = 0;
    int len = my_strlen(src);
    char *str = malloc(sizeof(char) * (len + 1));

    while (src[i] != '\0') {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
