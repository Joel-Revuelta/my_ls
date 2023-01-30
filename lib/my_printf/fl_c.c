/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** fl_c
*/

#include "my.h"
#include "my_printf.h"

int fl_c(va_list list, flags_t flags, int *len)
{
    if (flags.flag.minus == 1)
        my_putchar(va_arg(list, int));

    while (flags.min_w > 1) {
        my_putchar(' ');
        flags.min_w -= 1;
    }
    if (flags.flag.minus == 0)
        my_putchar(va_arg(list, int));
    *len += 1;
    return (0);
}
