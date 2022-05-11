/*
** EPITECH PROJECT, 2022
** victor header
** File description:
** DANTE_GENE_BASIC_FUNC
*/

#include "./../includes/library.h"

void print_1_down(s_var *all, int i, int j)
{
    if (all->array_map[i + 1][j] != 'o' && all->array_map[i + 2][j] != 'o') {
        all->array_map[i + 1][j] = '1';
        all->array_map[i + 2][j] = '1';
    }
}

void print_1_up(s_var *all, int i, int j)
{
    if (all->array_map[i - 1][j] != 'o' && all->array_map[i - 2][j] != 'o') {
        all->array_map[i - 1][j] = '1';
        all->array_map[i - 2][j] = '1';
    }
}

void check_vertical2(s_var *all, int i, int j)
{
    if (i < all->y_max && i >= 1) {
        if (j >= 0 && j <= all->x_max && (all->array_map[i - 1][j - 1] != 'o'
        && all->array_map[i - 2][j - 1] != 'o') || (all->array_map[i - 1][j +
        1] != 'o' && all->array_map[i - 2][j + 1] != 'o')) {
            print_1_up(all, i, j);
        }
    }
}

void check_vertical(s_var *all, int i, int j)
{
    if (i < all->y_max - 2 && i >= 0) {
        if (j >= 0 && j <= all->x_max && (all->array_map[i + 1][j - 1] != 'o'
        && all->array_map[i + 2][j - 1] != 'o') || (all->array_map[i + 1][j
        + 1] != 'o' && all->array_map[i + 2][j + 1] != 'o')) {
            print_1_down(all, i, j);
        }
    }
    check_vertical2(all, i, j);
}
