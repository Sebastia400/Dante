/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** Exercise myhunt page 1
*/

#include "./../includes/library.h"

void print_array_strings(char **array, int ini, int x_max)
{
    int i = ini;
    int j = 0;
    while (i <= x_max) {
        write(1, array[i], strlen(array[i]));
        if (array[i + 1] != NULL)
            my_putchar('\n');
        i++;
    }
}
