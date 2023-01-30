/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** my_nbrlen
*/

int my_nbrlen(double nb)
{
    int a = 0;
    long long b = pos_n(nb);

    if (nb >= 0 && nb < 9) {
        a = 1;
        return (a);
    }
    while (b >= 1) {
        b /= 10;
        a++;
    }
    return (a);
}
