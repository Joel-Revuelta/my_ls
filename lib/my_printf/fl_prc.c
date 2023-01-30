/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** fl_prc
*/

#include "my.h"
#include "my_printf.h"

int fl_prc(va_list list, flags_t flags, int *len)
{
    my_putchar('%');
    *len += 1;
    return (1);
}
