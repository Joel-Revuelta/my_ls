/*
** EPITECH PROJECT, 2022
** CPool_06
** File description:
** my_showstr
*/

#include "my.h"

void print_hexa(int nb)
{
    int temp;
    int i = 1;
    char res[3];
    while (nb != 0) {
        temp = nb % 16;
        if (temp < 10)
            temp += 48;
        else
            temp += 87;
        res[i++] = temp;
        nb /= 16;
    }
    write(1, "\\", 1);
    if (i == 2)
        write(1, "0", 1);
    while (i > 0) {
        write(1, &res[i], 1);
        i--;
    }
}

int my_showstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] > 126)
            print_hexa(str[i]);
        else
            write(1, &str[i], 1);
        i++;
    }
    return (0);
}
