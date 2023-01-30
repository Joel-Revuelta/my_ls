/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** my_printf
*/

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_

    #include <stdarg.h>
    #include <stdint.h>

    typedef struct flag_s {
        int minus;
        int plus;
        int zero;
        int blank;
        int hash;
    } flag_t;

    typedef struct flags_s {
        flag_t flag;
        int min_w;
        int p;
        int prec;
    } flags_t;

    typedef struct fnc_s {
        char c;
        int (*ptr)(va_list list, flags_t flags, int *len);
    } fnc_t;

    int my_printf(const char *format, ...);
    int get_flags(char *format, int i, flags_t *flags);
    char *create_arg(flags_t flags, char *c);
    void print_spaces(int strlen, int min_w, int *len);
    char *do_as_gflag(char *dec, int prec);
    long double e_round_dec(double a, int prec, long double b);
    long double e_round(double a);
    int fl_c(va_list list, flags_t flags, int *len);
    int fl_d(va_list list, flags_t flags, int *len);
    int fl_prc(va_list list, flags_t flags, int *len);
    int fl_s(va_list list, flags_t flags, int *len);
    int fl_x(va_list list, flags_t flags, int *len);
    int fl_xx(va_list list, flags_t flags, int *len);
    int fl_u(va_list list, flags_t flags, int *len);
    int fl_ss(va_list list, flags_t flags, int *len);
    int fl_b(va_list list, flags_t flags, int *len);
    int fl_o(va_list list, flags_t flags, int *len);
    int fl_n(va_list list, flags_t flags, int *len);
    int fl_p(va_list list, flags_t flags, int *len);
    int fl_ff(va_list list, flags_t flags, int *len);

#endif /* !MY_PRINTF_H_ */
