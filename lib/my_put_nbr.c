/*
** EPITECH PROJECT, 2022
** CPool_03
** File description:
** my_put_nbr
*/

#include "my.h"

int my_put_nbr(long nb)
{
    int num;
    int l = 1;

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
        l++;
    }
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
        return (1);
    }
    if (nb > 9) {
        num = nb % 10;
        l += my_put_nbr(nb / 10);
        my_putchar(num + 48);
        return (l);
    }
    return (0);
}
