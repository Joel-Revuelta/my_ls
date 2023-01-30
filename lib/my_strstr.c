/*
** EPITECH PROJECT, 2022
** CPool_06
** File description:
** my_strstr
*/

#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int temp = 0;
    int calc = 0;
    int i = 0;
    int j = 0;
    int len = my_strlen(to_find);

    while (str[i] != '\0') {
        temp = i;
        while (str[i] == to_find[j] && to_find[j] != '\0') {
            i++;
            j++;
        }
        calc = i - j;
        if (len == j)
            return (str + calc);
        i = temp + 1;
        j = 0;
    }
    return (NULL);
}
