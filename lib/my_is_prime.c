/*
** EPITECH PROJECT, 2022
** CPool_05
** File description:
** my_compute_power_it
*/

int my_is_prime(int nb)
{
    int i = 2;
    float rest = nb % i;

    if (nb == 2)
        return (1);
    while (rest != 0) {
        i++;
        rest = nb % i;
        if (i > nb)
            return (0);
        if (i == nb && rest == 0)
            return (1);
    }
    return (0);
}
