/*
** EPITECH PROJECT, 2022
** CPool_04
** File description:
** my_swap
*/

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
