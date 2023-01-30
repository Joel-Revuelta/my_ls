/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** fl_o
*/

#include "my.h"
#include "my_printf.h"

char *convert_to_octal(long int nb)
{
    char *str = malloc(sizeof(char) * my_int_len(nb) + 1);
    int i = 0;

    while (nb > 0) {
        str[i] = nb % 8 + 48;
        nb /= 8;
        i++;
    }
    return (my_revstr(str));
}

void print_octal(flags_t flags, char *str, int *len)
{
    int l = my_strlen(str);
    if (flags.prec > len)
        l = flags.prec;
    if (flags.flag.hash)
        l += 1;
    for (int i = l; !flags.flag.minus && i < flags.min_w; i++, *len += 1)
        my_putchar(' ');
    if (flags.flag.hash) {
        my_putchar('0');
        *len += 1;
    }
    for (int i = my_strlen(str); flags.p && i < flags.prec; i++, *len += 1, l++)
        my_putchar('0');
    my_putstr(str);
    *len += my_strlen(str);
    for (int i = l; flags.flag.minus && i < flags.min_w; i++, *len += 1)
        my_putchar(' ');
}

int fl_o(va_list list, flags_t flags, int *len)
{
    int nb = va_arg(list, int);
    long int nb2 = 0;
    char *str = NULL;

    if (nb < 0) {
        nb2 = 4294967296 + nb;
        str = convert_to_octal(nb2);
    } else
        str = convert_to_octal(nb);
    print_octal(flags, str, len);
    free(str);
    return (0);
}
