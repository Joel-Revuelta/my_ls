/*
** EPITECH PROJECT, 2021
** my_strstr
** File description:
** the behavior of the str_str function
*/

int my_charisalpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    if (c >= 'A' && c <= 'Z')
        return (2);
    if (c >= '0' && c <= '9')
        return (3);
    return (0);
}

char my_capitalizer(char c, char b)
{
    if (my_charisalpha(c) == 1 && my_charisalpha(b) == 0)
        c -= 32;
    if (my_charisalpha(c) == 2 && my_charisalpha(b) != 0)
        c += 32;
    return (c);
}

char *my_strcapitalize(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        str[i] = my_capitalizer(str[i], str[i - 1]);
        i++;
    }
    return (str);
}
