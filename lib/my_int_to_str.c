/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** my_int_to_str
*/

#include "my.h"

char *inttostr(int nbr, int len, char *res, int negat)
{
    int rest;
    if (negat == 1) {
        res[0] = '-';
        len++;
    }
    while (len > negat) {
        rest = nbr % 10;
        nbr /= 10;
        res[len - 1] = rest + 48;
        len--;
    }
    return (res);
}

char *my_int_to_str(int nbr)
{
    int len = 1;
    int temp = 10;
    char *res = malloc(sizeof(char) * 14);
    int negat = 0;

    if (nbr < 0) {
        nbr *= -1;
        negat++;
    }
    while (temp <= nbr) {
        len++;
        temp *= 10;
    }
    res[len + negat] = '\0';
    res = inttostr(nbr, len, res, negat);
    return (res);
}
