/*
** EPITECH PROJECT, 2022
** bs_myls
** File description:
** open_file
*/

#include "my.h"

char *open_file(char *file)
{
    struct stat st;
    stat(file, &st);

    int fd = open(file, O_RDONLY);
    char *buffer = malloc(sizeof(char) * st.st_size);

    read(fd, buffer, st.st_size);
    close(fd);
    return (buffer);
}
