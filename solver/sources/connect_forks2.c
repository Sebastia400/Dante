/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-victor.gonzalez
** File description:
** main.c
*/

#include "./../includes/library.h"

void delete_hor(s_var *all, int pos_i, int pos_j)
{
    int i = pos_i;
    int j = pos_j;

    while (j < all->x_max && all->array_map[i][j + 1] == '1') {
        j++;
        all->array_map[i][j] = '*';
    }
    j = pos_j;
    while (j > 0 && all->array_map[i][j - 1] == '1') {
        j--;
        all->array_map[i][j] = '*';
    }
}

void delete_vert(s_var *all, int pos_i, int pos_j)
{
    int i = pos_i;
    int j = pos_j;

    while (i > 0 && all->array_map[i - 1][j] == '1') {
        i--;
        all->array_map[i][j] = '*';
    }
    i = pos_i;
    while (all->array_map[i + 1] != NULL && all->array_map[i + 1][j] == '1') {
        i++;
        all->array_map[i][j] = '*';
    }
}
