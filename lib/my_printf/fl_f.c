/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** fl_ff
*/

#include "my.h"
#include "my_printf.h"

void print_float(flags_t flags, char *ent, char *dec, int *ln)
{
    int l = my_strlen(ent) + my_strlen(dec) + 1, point = 1;
    if (flags.p && !flags.prec && !flags.flag.hash) {
        l -= 1;
        point = 0;
    }
    if (my_getnbr(ent) > 0 && (flags.flag.blank || flags.flag.plus))
        l += 1;
    for (; !flags.flag.minus && l < flags.min_w && !flags.flag.zero; l++, *ln++)
        my_putchar(' ');
    if (flags.flag.blank && my_getnbr(ent) > 0)
        *ln += my_putstr(" ");
    if (flags.flag.plus && my_getnbr(ent) > 0)
        *ln += my_putstr("+");
    for (; !flags.flag.minus && l < flags.min_w && flags.flag.zero; l++, *ln++)
        my_putchar('0');
    *ln += my_putstr(ent);
    if (point)
        *ln += my_putstr(".");
    *ln += my_putstr(dec);
    for (; flags.flag.minus && l < flags.min_w; l++, *ln += 1, my_putchar(' '));
}

char *putdel_zero(char *str, int x)
{
    if (str[0] == '0' && x == 0) {
        for (int i = 0; str[i]; i++)
            str[i] = str[i + 1];
    }
    if (x == 1) {
        for (int i = my_strlen(str); i >= 0; i--)
            str[i + 1] = str[i];
        str[0] = '0';
    }
    return (str);
}

void my_round(char *ent, char *dec)
{
    int ent_len = my_strlen(ent), dec_len = my_strlen(dec), last = 0;
    if (dec[dec_len - 1] >= '5')
        dec[dec_len - 2] += 1;
    for (dec_len -= 1; dec_len >= 0; dec_len--) {
        if (dec[dec_len] > '9' || (dec[0] >= '5' && dec[1] == '\0')) {
            dec[dec_len] = '0';
            dec[dec_len - 1] += 1;
            last = 1;
        } else
            last = 0;
    }
    dec[my_strlen(dec) - 1] = '\0';
    if (last == 1)
        ent[ent_len - 1] += 1;
    for (ent_len -= 1; ent_len >= 0; ent_len--) {
        if (ent[ent_len] > '9') {
            ent[ent_len] = '0';
            ent[ent_len - 1] += 1;
        }
    }
}

void floats_flag(double nb, flags_t flags, int *len)
{
    long long int ent = (long long int)nb;
    nb -= ent;
    char *dec = NULL, *str_ent = putdel_zero(my_int_to_str(ent), 1);
    if (nb < 0)
        nb *= -1;
    if (!flags.p)
        flags.prec = 6;
    dec = malloc(sizeof(char) * (flags.prec + 2));
    for (int i = 0; i <= flags.prec; i++, dec[i] = '\0') {
        nb *= 10;
        dec[i] = (int)nb % 10 + '0';
        nb -= (int)nb;
    }
    my_round(str_ent, dec);
    str_ent = putdel_zero(str_ent, 0);
    print_float(flags, str_ent, dec, len);
}

int fl_ff(va_list list, flags_t flags, int *len)
{
    double nb = va_arg(list, double);
    floats_flag(nb, flags, len);
    return (0);
}
