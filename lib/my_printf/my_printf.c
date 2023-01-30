/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** my_printf
*/

#include "my.h"
#include "my_printf.h"

fnc_t *init_fnc(fnc_t *fnc)
{
    fnc = malloc(sizeof(fnc_t) * 15);
    fnc[0] = (fnc_t){'c', fl_c};
    fnc[1] = (fnc_t){'d', fl_d};
    fnc[2] = (fnc_t){'i', fl_d};
    fnc[3] = (fnc_t){'s', fl_s};
    fnc[4] = (fnc_t){'%', fl_prc};
    fnc[5] = (fnc_t){'x', fl_x};
    fnc[6] = (fnc_t){'X', fl_xx};
    fnc[7] = (fnc_t){'u', fl_u};
    fnc[8] = (fnc_t){'S', fl_ss};
    fnc[9] = (fnc_t){'b', fl_b};
    fnc[10] = (fnc_t){'o', fl_o};
    fnc[11] = (fnc_t){'n', fl_n};
    fnc[12] = (fnc_t){'p', fl_p};
    fnc[12] = (fnc_t){'f', fl_ff};
    fnc[13] = (fnc_t){'F', fl_ff};
    fnc[14] = (fnc_t){'\0', NULL};
    return (fnc);
}

int call_fnc(va_list list, char const *format, int i, int *len)
{
    fnc_t *fnc = init_fnc(fnc);
    int f = 0;
    flags_t flags;
    i = g_fl(format, i, &flags);

    while (fnc[f].c) {
        if (fnc[f].c == format[i]) {
            fnc[f].ptr(list, flags, len);
        }
        f++;
    }
    free(fnc);
    return (i);
}

int is_fl(char c)
{
    char *str = "cdis%xXuSbonpfFgeE";

    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            return (1);
    }
    return (0);
}

int my_printf(const char *format, ...)
{
    va_list list;
    flags_t fl;
    va_start(list, format);
    int i = 0;
    int len = 0;

    while (format[i]) {
        if (format[i] == '%' && is_fl(format[g_fl(format, i + 1, &fl)])) {
            i = call_fnc(list, format, i + 1, &len);
        } else {
            my_putchar(format[i]);
            len++;
        }
        i++;
    }
    va_end(list);
    return (len);
}
