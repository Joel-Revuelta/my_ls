/*
** EPITECH PROJECT, 2022
** CPool_06
** File description:
** my_revstr
*/

#include "my.h"

char *my_revstr(char *str)
{
    char tmp;
    int len = my_strlen(str) - 1;
    int i = 0;

    while (i < len) {
        tmp = str[i];
        str[i] = str[len];
        str[len] = tmp;
        len--;
        i++;
    }
    return (str);
}
