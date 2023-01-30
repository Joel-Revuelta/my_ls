/*
** EPITECH PROJECT, 2022
** CPool_05
** File description:
** my_find_prime_sup
*/

int check_prime(int rest, int nb, int i)
{
    while (rest != 0) {
        i++;
        rest = nb % i;
        if (i > nb)
            rest = 0;
        if (i == nb && rest == 0)
            return (1);
    }
    return (0);
}

int my_find_prime_sup(int nb)
{
    int i = 1;
    float rest = 1;

    if (nb < 2)
        return (2);
    while (1) {
        if (check_prime(rest, nb, i))
            return (nb);
        i = 2;
        nb++;
    }
}
