/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** fl_s
*/

#include "my.h"
#include "my_printf.h"

void print_spaces(int strlen, int min_w, int *len)
{
    for (int i = 0; strlen + i < min_w; i++) {
            my_putchar(' ');
            *len += 1;
    }
}

void my_put_str_flags(char *str, flags_t flags, int *len)
{
    int strlen = my_strlen(str);
    if (flags.p && strlen > flags.prec)
        strlen = flags.prec;
    if (strlen < flags.min_w && flags.flag.minus == 0)
        print_spaces(strlen, flags.min_w, len);
    if (flags.p == 1 && flags.prec >= 0) {
        for (int i = 0; i < flags.prec && str[i]; i++) {
            my_putchar(str[i]);
            *len += 1;
        }
    } else
        my_putstr(str);
    if (strlen < flags.min_w && flags.flag.minus == 1)
        print_spaces(strlen, flags.min_w, len);
}

int fl_s(va_list list, flags_t flags, int *len)
{
    char *str = my_strdup(va_arg(list, char *));
    if (!str) {
        my_putstr("(null)");
        *len += 6;
        return (0);
    }
    if (!flags.p && !flags.min_w && !flags.prec) {
        my_putstr(str);
        *len += my_strlen(str);
    } else {
        my_put_str_flags(str, flags, len);
    }
    free(str);
    return (0);
}
