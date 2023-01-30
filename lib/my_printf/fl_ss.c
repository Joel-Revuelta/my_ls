/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** fl_S
*/

#include "my.h"
#include "my_printf.h"

char *print_oct(int nb, char *res)
{
    char *str = malloc(sizeof(char) * my_int_len(nb) + 1);
    int i = 0;
    int count = 1;

    while (nb > 0) {
        str[i] = nb % 8 + 48;
        nb /= 8;
        i++;
    }
    str[i] = '\0';
    for (; my_strlen(str) < 3; i++) {
        str[i] = '0';
        str[i + 1] = '\0';
    }
    str[i] = '\\';
    str[i + 1] = '\0';
    res = my_strcat(res, my_revstr(str));
    free(str);
    return (res);
}

int fl_ss(va_list list, flags_t flags, int *len)
{
    char *str = va_arg(list, char *);
    char *res = malloc(sizeof(res));
    char *format = malloc(sizeof(format));
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] > 126)
            res = print_oct(str[i], res);
        else
            res[my_strlen(res)] = str[i];
        i++;
    }
    res[my_strlen(res)] = '\0';
    format = create_arg(flags, "s");
    *len += my_printf(format, res);
    free(res);
    free(format);
    return (0);
}
