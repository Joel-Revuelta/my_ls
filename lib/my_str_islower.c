/*
** EPITECH PROJECT, 2022
** CPool_06
** File description:
** my_str_islower
*/

#include "my.h"

int my_str_islower(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (1);
    while (str[i] != '\0') {
        if (str[i] < 'a' || str[i] > 'z')
            return (0);
        i++;
    }
    return (1);
}
