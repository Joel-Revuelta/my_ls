/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** fl_b
*/

#include "my.h"
#include "my_printf.h"

int fl_b(va_list list, flags_t flags, int *len)
{
    long nbr = va_arg(list, long);
    char *bi = malloc(sizeof(char) * 100);
    int i = 0;
    char *str = NULL;

    while (nbr > 0) {
        bi[i] = (nbr % 2) + 48;
        nbr /= 2;
        i++;
    }
    bi[i] = '\0';
    str = create_arg(flags, "s");
    *len += my_printf(str, my_revstr(bi));
    free(str);
    free(bi);
    return (0);
}
