/*
** EPITECH PROJECT, 2022
** CPool_06
** File description:
** my_strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int x1 = 0;
    int x2 = 0;

    while (n > 0) {
        x1 += s1[i];
        x2 += s2[i];
        i++;
        n--;
    }
    return (x1 - x2);
}
