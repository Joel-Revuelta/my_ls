/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** fl_xx
*/

#include "my.h"
#include "my_printf.h"

int add_spaces2(char *res, flags_t flags, int x)
{
    int len = x;
    int i = 0;

    if (flags.prec > len)
        len = flags.prec;
    if (flags.flag.hash)
        len += 2;
    for (; flags.flag.minus && len < flags.min_w; res[i] = ' ', i++, len++);
    return (i);
}

char *finish_hexa2(char *res, flags_t flags, int i, int i2)
{
    for (; flags.p && i2 < flags.prec; res[i] = '0', i++, i2++);
    if (flags.flag.hash) {
        res[i] = 'X';
        res[i + 1] = '0';
        i += 2;
    }
    for (; !flags.flag.minus && i < flags.min_w; res[i] = ' ', i++);
    res[i] = '\0';
}

void hexa2(int nb, flags_t flags, int *len)
{
    char *res = malloc(sizeof(res)), *c = "0123456789ABCDEF0";
    int temp = 0, rem = 0, i = add_spaces2(res, flags, 0), i2 = 0, old = 0;

    while (nb != 0) {
        temp = nb % 16;
        res[i++] = c[temp];
        old = nb;
        nb /= 16;
        i2++;
    }
    finish_hexa2(res, flags, i, i2);
    my_putstr(my_revstr(res));
    *len += my_strlen(my_revstr(res));
}

void neg_hexa2(int nb, flags_t flags, int *len)
{
    char *res = malloc(sizeof(res)), *c = "0123456789ABCDEF0";
    int temp = 0, rem = 0, i = add_spaces2(res, flags, 8), i2 = 0, old = 0;

    while (nb != 0) {
        if (temp == 16 && nb != 1)
            nb --;
        if (old > 16)
            nb++;
        temp = 16 - (nb % 16);
        res[i++] = c[temp];
        old = nb;
        nb /= 16;
        i2++;
    }
    for (; i2 < 8; res[i] = 'F', i++, i2++);
    finish_hexa2(res, flags, i, i2);
    my_putstr(my_revstr(res));
    *len += my_strlen(my_revstr(res));
}

int fl_xx(va_list list, flags_t flags, int *len)
{
    int nb = va_arg(list, int);

    if (nb >= 0)
        hexa2(nb, flags, len);
    else
        neg_hexa2(nb * -1, flags, len);
}
