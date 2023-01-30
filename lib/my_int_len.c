/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** my_int_len
*/

int	my_int_len(int nb)
{
    int	div = 1;
    int	count = 1;

    if (nb == 0)
        return (1);
    if (nb < 0)
        nb *= -1;
    while (nb / div >= 1) {
        div = div * 10;
        count += 1;
    }
    return (count - 1);
}
