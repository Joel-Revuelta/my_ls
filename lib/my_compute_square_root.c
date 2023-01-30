/*
** EPITECH PROJECT, 2022
** CPool_05
** File description:
** my_compute_square_root
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    int i = 0;
    int res = 0;

    if (nb < 0)
        return (0);
    while (res < nb) {
        res = i * i;
        if (res == nb)
            return (i);
        i++;
    }
    return (0);
}
