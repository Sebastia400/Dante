/*
** EPITECH PROJECT, 2022
** victor header
** File description:
** DANTE_GENE_BASIC_FUNC
*/

#include "./../includes/library.h"

void fill_map_borders(s_var *all)
{
    int i = all->y_max - 1;
    int j = all->x_max - 1;
    int rand_dir = rand() % 2;

    all->array_map[i][j] = 'o';
    if (rand_dir)
        fill_map_borders_1(all);
    else
        fill_map_borders_2(all);
}

void fill_map_borders_1(s_var *all)
{
    int i = all->y_max - 1;
    int j = all->x_max - 1;

    while (j-- > 0) {
        if (!(j % 2) && !((i - 1) % 2) && all->array_map[i - 1][j] == 'o')
            all->array_map[i][j] = 'o';
    }
    i = all->y_max - 1;
    j = all->x_max - 1;
    while (i-- > 0) {
        if ((j % 2) && (i % 2) && all->array_map[i][j - 1] == 'o')
            all->array_map[i][j] = 'o';
    }
}

void fill_map_borders_2(s_var *all)
{
    int i = all->y_max - 1;
    int j = all->x_max - 1;

    while (j-- > 0) {
        if ((j % 2) && (i % 2) && all->array_map[i - 1][j] == 'o')
            all->array_map[i][j] = 'o';
    }
    i = all->y_max - 1;
    j = all->x_max - 1;
    while (i-- > 0) {
        if (!((j - 1) % 2) && !(i % 2) && all->array_map[i][j - 1] == 'o')
            all->array_map[i][j] = 'o';
    }
}
