/*
** EPITECH PROJECT, 2022
** CPool_04
** File description:
** my_putstr
*/

#include "my.h"

int my_putstr(char const *str)
{
    int len = 0;

    if (str == NULL)
        return (0);
    len = my_strlen(str);
    write(1, str, len);
    return (len);
}
