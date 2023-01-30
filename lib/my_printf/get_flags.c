/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** get_flags
*/

#include "my.h"
#include "my_printf.h"

int is_flag(char c, char *str)
{
    for (int j = 0; str[j]; j++) {
        if (str[j] == c)
            return (1);
    }
    return (0);
}

int g_fl1(flag_t *flag, char *format, int i)
{
    flag->minus = 0;
    flag->plus = 0;
    flag->zero = 0;
    flag->blank = 0;
    flag->hash = 0;
    for (int j = 0; is_flag(format[i], "-+0 #"); j++) {
        if (format[i] == '-')
            flag->minus = 1;
        if (format[i] == '+')
            flag->plus = 1;
        if (format[i] == '0')
            flag->zero = 1;
        if (format[i] == ' ')
            flag->blank = 1;
        if (format[i] == '#')
            flag->hash = 1;
        i++;
    }
    return (i);
}

int g_fl(char *format, int i, flags_t *flags)
{
    i = g_fl1(&flags->flag, format, i);
    char *str = my_strdup_from(format, i);
    flags->min_w = my_getnbr(str);
    if (flags->min_w != 0)
        i += my_int_len(flags->min_w);
    if (format[i] == '.') {
        flags->p = 1;
        i++;
    } else
        flags->p = 0;
    str = my_strdup_from(format, i);
    flags->prec = my_getnbr(str);
    if (flags->prec != 0 || flags->p == 1 && format[i] == '0')
        i += my_int_len(flags->prec);
    for (; is_flag(format[i], "lhqLjzZt"); i++);
    return (i);
}
