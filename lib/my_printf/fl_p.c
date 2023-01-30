/*
** EPITECH PROJECT, 2022
** printf
** File description:
** fl_p
*/

#include "my.h"
#include "my_printf.h"

int fl_p(va_list list, flags_t flags, int *len)
{
    uintptr_t a = (uintptr_t)va_arg(list, void*);
    char *format = malloc(sizeof(format));
    char *chars = "0123456789abcdef";
    int temp = 0;
    char *str = malloc(8 * *len);
    int i = 0;

    format = create_arg(flags, "s");
    for (temp; a != 0; temp = a % 16, str[i] = chars[temp], i++, a /= 16);
    str[i] = 'x';
    str[i + 1] = '0';
    str[i + 2] = '\0';
    *len += my_printf(format, my_revstr(str));
    return (0);
}
