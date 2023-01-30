/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** get_args
*/

#include "my.h"
#include "my_ls.h"

char *get_file_type(struct stat st)
{
    if (S_ISREG(st.st_mode))
        return ("-");
    if (S_ISDIR(st.st_mode))
        return ("d");
    if (S_ISCHR(st.st_mode))
        return ("c");
    if (S_ISBLK(st.st_mode))
        return ("b");
    if (S_ISSOCK(st.st_mode))
        return ("s");
    if (S_ISLNK(st.st_mode))
        return ("l");
}

char *get_perms(struct stat st)
{
    char *str = malloc(sizeof(char) * 11);

    str[0] = '\0';
    str = my_strcat(str, get_file_type(st));
    str = my_strcat(str, (st.st_mode & S_IRUSR) ? "r" : "-");
    str = my_strcat(str, (st.st_mode & S_IWUSR) ? "w" : "-");
    str = my_strcat(str, (st.st_mode & S_IXUSR) ? "x" : "-");
    str = my_strcat(str, (st.st_mode & S_IRGRP) ? "r" : "-");
    str = my_strcat(str, (st.st_mode & S_IWGRP) ? "w" : "-");
    str = my_strcat(str, (st.st_mode & S_IXGRP) ? "x" : "-");
    str = my_strcat(str, (st.st_mode & S_IROTH) ? "r" : "-");
    str = my_strcat(str, (st.st_mode & S_IWOTH) ? "w" : "-");
    str = my_strcat(str, (st.st_mode & S_IXOTH) ? "x" : "-");
    if (st.st_mode & S_ISUID)
        str[3] = 's';
    if (st.st_mode & S_ISGID)
        str[6] = 's';
    if (st.st_mode & S_ISVTX)
        str[9] = 't';
    return (str);
}

char *clean_time(char *str)
{
    int i = 4;
    while (str[i + 9]) {
        str[i - 4] = str[i];
        i++;
    }
    str[i - 4] = '\0';
    return (str);
}

args_t *get_args(int ac, char **av, flags_t *flags, int *status)
{
    args_t *files = NULL;
    struct stat st;
    int x = 0;

    for (int i = 1; i < ac; i++) {
        if (av[i][0] != '-' && stat(av[i], &st) >= 0)
            my_put_in_list(&files, my_strdup(av[i]), st, 0);
        if (av[i][0] != '-' && stat(av[i], &st) < 0) {
            perror(my_strmcat(my_strmcat("ls: cannot access '", av[i]), "'"));
            *status = 84;
        }
        if (av[i][0] != '-')
            x = 1;
    }
    if (x == 0 && stat(".", &st) >= 0)
        my_put_in_list(&files, ".", st, 0);
    my_revlist(&files);
    return (files);
}
