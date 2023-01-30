/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** my_ls
*/

#include "my.h"
#include "my_ls.h"

void print_file(args_t *file, flags_t *flags)
{
    args_t *tmp = file;
    args_t *last = file;

    for (;tmp; tmp = tmp->next) {
        if (tmp->name[0] != '.')
            last = tmp;
    }
    if (!flags->a && file->name[0] == '.')
        return;
    if (flags->l) {
        my_printf("%s %d %s %s %d %s %s\n", file->perm, file->hard_l,
        file->user, file->group, file->size, file->time, file->name);
    } else {
        my_putstr(file->name);
        if ((file->next && flags->a) || (!flags->a && file != last))
            my_putchar(' ');
        else
            my_putchar('\n');
    }
}

int print_ls(flags_t *flags, args_t *args)
{
    DIR *dir = NULL;
    int status = 0;

    for (args_t *tmp = args; tmp; tmp = tmp->next) {
        if (tmp->perm[0] == 'd' && (dir = opendir(tmp->name)))
            print_dir(opendir(tmp->name), tmp,flags);
        if (tmp->perm[0] == 'd' && !opendir(tmp->name)) {
            perror(my_strmcat(my_strmcat("ls: cannot open directory '",
            tmp->name), "'"));
            status = 84;
        }
        if (tmp->perm[0] == '-')
            print_file(tmp, flags);
    }
    return (status);
}

int my_ls(int ac, char **av, flags_t *flags)
{
    int status = 0;
    int tmp = 0;
    args_t *args = get_args(ac, av, flags, &status);

    if (flags->r)
        my_revlist(&args);
    tmp = print_ls(flags, args);
    if (tmp > status)
        status = tmp;
    return (status);
}
