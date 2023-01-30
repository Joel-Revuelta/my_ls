/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** main
*/

#include "my.h"
#include "my_ls.h"

void get_flags(flags_t *flags, char *str)
{
    char *fl = "larRtd";
    for (int i = 0; str[i]; i++) {
        if (str[i] == 'l')
            flags->l = 1;
        if (str[i] == 'a')
            flags->a = 1;
        if (str[i] == 'R')
            flags->R = 1;
        if (str[i] == 'd')
            flags->d = 1;
        if (str[i] == 'r')
            flags->r = 1;
        if (str[i] == 't')
            flags->t = 1;
    }
}

flags_t *init_flags(int ac, char **av)
{
    flags_t *flags = malloc(sizeof(flags_t));
    flags->a = 0;
    flags->d = 0;
    flags->l = 0;
    flags->R = 0;
    flags->r = 0;
    flags->t = 0;
    for (int i = 0; i < ac; i++) {
        if (av[i][0] == '-')
            get_flags(flags, av[i]);
    }
    return (flags);
}

int main(int ac, char **av)
{
    flags_t *flags = init_flags(ac, av);
    int status = my_ls(ac, av, flags);

    return (status);
}
