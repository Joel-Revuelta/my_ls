/*
** EPITECH PROJECT, 2022
** CPool_05
** File description:
** my_compute_power_rec
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (1);
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}
