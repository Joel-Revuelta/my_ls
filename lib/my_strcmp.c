/*
** EPITECH PROJECT, 2022
** CPool_06
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int x1 = 0;
    int x2 = 0;

    while (s1[i] != '\0' || s2[i] != '\0') {
        x1 += s1[i];
        x2 += s2[i];
        i++;
    }
    return (x1 - x2);
}
