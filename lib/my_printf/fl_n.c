/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** fl_n
*/

#include "my.h"
#include "my_printf.h"

int fl_n(va_list list, flags_t flags, int *len)
{
    int *x = va_arg(list, int *);

    *x = *len;
    return (0);
}
