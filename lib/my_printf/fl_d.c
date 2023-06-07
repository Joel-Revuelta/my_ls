/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** fl_d
*/

#include "my.h"
#include "my_printf.h"

void puc(char c)
{
    write(1, &c, 1);
}

int fl_min_pl(flags_t flags, int nb, int *len)
{
    int ln = my_int_len(nb);
    if (flags.prec > ln) {
        ln = flags.prec;
    }
    if (nb > 0 && flags.flag.blank && !flags.flag.plus && flags.min_w > ln) {
        *len += 1;
        my_putchar(' ');
    }
    if (nb < 0) {
        nb *= -1;
        *len += 1;
        my_putchar('-');
    } else if (flags.flag.plus) {
        *len += 1;
        my_putchar('+');
    }
    return (nb);
}

int fl_d(va_list list, flags_t flags, int *len)
{
    int nb = va_arg(list, int);
    int int_len = my_int_len(nb);

    if (nb < 0 || flags.flag.plus || (flags.flag.blank && flags.flag.minus))
        flags.min_w -= 1;
    if (flags.flag.zero)
        flags.prec = flags.min_w;
    if (int_len < flags.prec)
        int_len = flags.prec;
    for (; !flags.flag.minus && flags.min_w > int_len; flags.min_w--, *len += 1)
        my_putchar(' ');
    nb = fl_min_pl(flags, nb, len);
    for (int cpy = int_len; cpy > my_int_len(nb); cpy--, *len += 1, puc('0'));
    my_put_nbr(nb);
    for (; flags.flag.minus && flags.min_w > int_len; flags.min_w--, *len += 1)
        my_putchar(' ');
    *len += my_int_len(nb);
    return (0);
}
