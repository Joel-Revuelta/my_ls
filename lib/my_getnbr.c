/*
** EPITECH PROJECT, 2022
** CPool_04
** File description:
** my_getnbr
*/

#include "my.h"

int check_num(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int check_op(char c, int value)
{
    if (c == '+' && value != 0)
        return (0);
    if (c == '-' && value != 0)
        return (0);
    if (c != '+' && c != '-')
        return (0);
    return (1);
}

int my_getnbr(char const *str)
{
    int value = 0;
    int i = 0;
    int sign = 1;

    while (str[i] != '\0') {
        if (str[i] == '-')
            sign = (-1);
        if (!check_num(str[i]) && !check_op(str[i], value))
            return (value *sign);
        if (check_num(str[i]))
            value = value * 10 + (str[i] - '0');
        i++;
    }
    return (value * sign);
}
