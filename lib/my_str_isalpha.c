/*
** EPITECH PROJECT, 2022
** CPool_05
** File description:
** my_compute_power_rec
*/

#include "my.h"

int my_char_isalpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}

int my_str_isalpha(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (1);
    while (str[i] != '\0') {
        if (!my_char_isalpha(str[i]))
            return (0);
        i++;
    }
    return (1);
}
