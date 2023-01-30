/*
** EPITECH PROJECT, 2022
** CPool_04
** File description:
** my_sort_int_array
*/

void my_sort_int_array_2(int *array, int size)
{
    int i = 0;
    int tmp = 0;

    while (i < size - 1) {
        if (array[i] > array[i + 1]) {
            tmp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = tmp;
        }
        i++;
    }
}

void my_sort_int_array(int *array, int size)
{
    int j = 0;

    while (j <= size - 1) {
        my_sort_int_array_2(array, size);
        j++;
    }
}
