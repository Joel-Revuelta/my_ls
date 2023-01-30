/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** fl_u
*/

#include "my.h"
#include "my_printf.h"

int	my_long_len(long long nb)
{
    long int	div = 1;
    long int	count = 1;

    if (nb == 0)
        return (1);
    while (nb / div >= 1) {
        div = div * 10;
        count += 1;
    }
    return (count - 1);
}

int fl_u(va_list list, flags_t flags, int *len)
{
    long long nb = va_arg(list, long long);
    long long int_len = my_long_len(nb);

    if (flags.flag.zero)
        flags.prec = flags.min_w;
    if (int_len < flags.prec)
        int_len = flags.prec;
    for (; !flags.flag.minus && flags.min_w > int_len; flags.min_w--, *len += 1)
        my_putchar(' ');
    for (int cpy = int_len; cpy > my_long_len(nb); cpy--, *len += 1, puc('0'));
    my_put_nbr(nb);
    for (; flags.flag.minus && flags.min_w > int_len; flags.min_w--, *len += 1)
        my_putchar(' ');
    *len += my_long_len(nb);
    return (0);
}
