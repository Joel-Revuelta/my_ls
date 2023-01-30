/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** print_ls
*/

#include "my.h"
#include "my_ls.h"

void add_to_recursive(args_t **recur, char *f_name, flags_t *flags)
{
    struct stat st;

    if (flags->R && f_name[my_strlen(f_name) - 1] != '.' &&
    stat(f_name, &st) >= 0 && opendir(f_name))
        my_put_in_list(recur, f_name, st, 1);
}

void print_format_dir(flags_t *flags, args_t *args, args_t *files, args_t *rec)
{
    if (!flags->r) {
        my_revlist(&files);
        my_revlist(&rec);
    }
    if (args->back || args->done_rec)
        my_putchar('\n');
    if (args->next || args->back || flags->R)
        my_printf("%s:\n", args->name);
    if (flags->l)
        my_printf("total %d\n", args->total);
    for (args_t *tmp = files; tmp; tmp = tmp->next)
        print_file(tmp, flags);
    if (flags->R) {
        print_ls(flags, rec);
    }
}

void print_dir(DIR *dir, args_t *args, flags_t *flags)
{
    struct dirent *dirent;
    struct stat st;
    args_t *files = NULL;
    args_t *recur = NULL;
    args->total = 0;
    char *str = my_strmcat(args->name, "/");
    char *f_name = malloc(sizeof(char) * 100);

    while ((dirent = readdir(dir)) != 0) {
        f_name = my_strmcat(str, dirent->d_name);
        if (stat(f_name, &st) >= 0 && ((!flags->a && dirent->d_name[0] != '.')
        || flags->a)) {
            my_put_in_list(&files, dirent->d_name, st, 0);
            args->total += st.st_blocks / 2;
            add_to_recursive(&recur, f_name, flags);
        }
    }
    print_format_dir(flags, args, files, recur);
}
