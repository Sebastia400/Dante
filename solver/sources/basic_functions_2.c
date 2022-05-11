/*
** EPITECH PROJECT, 2022
** victor header
** File description:
** Exercise myhunt page 1
*/

#include "./../includes/library.h"

void my_putchar(char letter)
{
    write(1, &letter, 1);
}

void my_putstr(char const *str)
{
    int len = 0;

    if (str) {
        len = my_strlen(str);
        if (len > 0)
            write(1, str, len);
    }
}

void prova_delete2(s_var *all, int i, int j)
{
    while (all->array_map[i][j] != '\0') {
        if (all->array_map[i][j] == '1')
            all->array_map[i][j] = '*';
        j++;
    }
}

void prova_delete(s_var *all)
{
    int i = 0;
    int j = 0;

    while (all->array_map[i] != NULL) {
        j = 0;
        prova_delete2(all, i, j);
        i++;
    }
}
