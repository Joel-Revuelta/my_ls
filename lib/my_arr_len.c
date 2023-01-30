/*
** EPITECH PROJECT, 2022
** bs_myls
** File description:
** my_arr_len
*/

int my_arr_len(char **arr)
{
    int i = 0;

    while (arr[i]) {
        i++;
    }
    return (i);
}
