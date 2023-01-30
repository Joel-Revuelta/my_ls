/*
** EPITECH PROJECT, 2022
** CPool_08
** File description:
** my_str_to_word_array
*/

#include "my.h"

int is_alphanum(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    if (c >= 'A' && c <= 'Z')
        return (1);
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int count_sep(char const *str, char c)
{
    int i = 0;
    int res = 0;

    while (str[i] != '\0') {
        if (str[i] == c)
            res++;
        i++;
    }
    return (res);
}

char **alloc_arr(char const *str, char c)
{
    int seps = count_sep(str, c);
    int str_len = my_strlen(str);
    char **res = malloc(sizeof(char *) * (seps + 1));
    int i = 0;

    while (i <= seps) {
        res[i] = malloc(sizeof(char) * (str_len + 1));
        i++;
    }
    return (res);
}

char **my_str_to_array(char const *str, char c)
{
    char **res = alloc_arr(str, c);
    int i = 0;
    int j = 0;
    int x = 0;

    while (str[i] != '\0') {
        if (str[i] == c) {
            res[j][x] = '\0';
            j++;
            x = 0;
        } else {
            res[j][x] = str[i];
            x++;
        }
        i++;
    }
    res[j + 1] = NULL;
    return (res);
}
