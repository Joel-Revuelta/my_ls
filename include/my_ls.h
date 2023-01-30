/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** my_ls
*/

#ifndef MY_LS_H_
    #define MY_LS_H_

    #include <sys/types.h>
    #include <sys/stat.h>
    #include <libgen.h>
    #include <sys/sysmacros.h>
    #include <time.h>
    #include <dirent.h>
    #include <pwd.h>
    #include <grp.h>

    typedef struct args_s {
        char *perm;
        int hard_l;
        char *user;
        char *group;
        int size;
        char *time;
        char *name;
        int total;
        int done_rec;
        struct args_s *next;
        struct args_s *back;
    } args_t;

    typedef struct flags_s {
        int l;
        int a;
        int R;
        int d;
        int r;
        int t;
    } flags_t;

    int my_ls(int ac, char **av, flags_t *flags);
    args_t *get_args(int ac, char **av, flags_t *flags, int *status);
    int my_put_in_list(args_t **list, char *name, struct stat st, int rec);
    void my_revlist(args_t **begin);
    char *get_perms(struct stat st);
    char *clean_time(char *str);
    void print_file(args_t *file, flags_t *flags);
    void print_dir(DIR *dir, args_t *args, flags_t *flags);

#endif /* !MY_LS_H_ */
