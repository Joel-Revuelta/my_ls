/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** create_arg
*/

#include "my.h"
#include "my_printf.h"

char *create_arg(flags_t flags, char *c)
{
    char *str = malloc(sizeof(str));
    str[0] = '%', str[1] = '\0';
    if (flags.flag.minus)
        str = my_strcat(str, "-");
    if (flags.flag.plus)
        str = my_strcat(str, "+");
    if (flags.flag.zero)
        str = my_strcat(str, "0");
    if (flags.flag.blank)
        str = my_strcat(str, " ");
    if (flags.flag.hash)
        str = my_strcat(str,"#");
    if (flags.min_w)
        str = my_strcat(str, my_int_to_str(flags.min_w));
    if (flags.p)
        str = my_strcat(str, ".");
    if (flags.prec)
        str = my_strcat(str, my_int_to_str(flags.prec));
    str = my_strcat(str, c);
    return (str);
}
