/*
** EPITECH PROJECT, 2022
** CPool_0
** File description:
** my_strlen
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    while (str[i])
        i++;
    return (i);
}
