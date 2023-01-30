/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** l_lists
*/

#include "my.h"
#include "my_ls.h"

int my_put_in_list(args_t **list, char *name, struct stat st, int rec)
{
    args_t *new = malloc(sizeof(args_t));
    struct passwd *pw = getpwuid(st.st_uid);
    struct group *gr = getgrgid(st.st_gid);

    new->name = my_strdup(name);
    new->hard_l = st.st_nlink;
    new->user = pw->pw_name;
    new->group = gr->gr_name;
    new->size = st.st_size;
    new->perm = get_perms(st);
    new->time = clean_time(my_strdup(ctime(&st.st_mtim)));
    new->done_rec = rec;
    if (*list)
        (*list)->back = new;
    new->back = NULL;
    new->next = *list;
    *list = new;
    return (0);
}

void my_revlist(args_t **begin)
{
    args_t *prev = NULL;
    args_t *next = NULL;
    args_t *back = NULL;
    args_t *curr = *begin;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        curr->back = next;
        prev = curr;
        curr = next;
    }
    *begin = prev;
}
