/*
** EPITECH PROJECT, 2022
** victor header
** File description:
** DANTE_GENE_BASIC_FUNC
*/

#include "./../includes/library.h"

void save_map(s_var *all, int x, int y)
{
    int i = 0;

    all->array_map = NULL;
    all->array_map = calloc(y + 1, sizeof(char *));
    while (i < y) {
        all->array_map[i] = calloc(x + 2, sizeof(char));
        all->array_map[i] = my_memset(all->array_map[i], '\0', x + 1);
        all->array_map[i] = my_memset(all->array_map[i], '*', x);
        i++;
    }
    all->array_map[i] = NULL;
    all->array_map[0][0] = 'o';
}

void clean_map2(s_var *all, int i, int j)
{
    while (all->array_map[i][j] != '\0') {
        if (all->array_map[i][j] == '1' || all->array_map[i][j] == '*'
        || all->array_map[i][j] == 'x')
            all->array_map[i][j] = 'X';
        else
            all->array_map[i][j] = '*';
        j++;
    }

}

void clean_map(s_var *all)
{
    int i = 0;
    int j = 0;

    while (all->array_map[i] != NULL) {
        j = 0;
        clean_map2(all, i, j);
        i++;
    }
}
