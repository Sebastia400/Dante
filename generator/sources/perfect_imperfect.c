/*
** EPITECH PROJECT, 2022
** victor header
** File description:
** DANTE_GENE_BASIC_FUNC
*/

#include "./../includes/library.h"

int check_connection_path(int i, int j, s_var *all)
{
    if (j > 1 && j < all->x_max - 1) {
        if (all->array_map[i][j - 1] == '*' && all->array_map[i][j + 1] == '*')
            return (1);
    }
    if (i > 1 && i < all->y_max - 1) {
        if (all->array_map[i - 1][j] == '*' && all->array_map[i + 1][j] == '*')
            return (1);
    }
    return (0);
}

int num_walls2(s_var *all, int i, int j, int num_walls)
{
    while (all->array_map[i][j] != '\0') {
        if (all->array_map[i][j] == 'X') {
            num_walls++;
            return (num_walls);
        }
        j++;
    }
    return (num_walls);
}

int num_walls(s_var *all)
{
    int i = 0;
    int j = 0;
    int num_walls = 0;

    while (all->array_map[i] != NULL) {
        j = 0;
        num_walls = num_walls2(all, i, j, num_walls);
        i++;
    }
    return (num_walls);
}

int imperfect_map2(s_var *all, int i, int j, int num_wall)
{
    while (all->array_map[i][j] != '\0') {
        if (all->array_map[i][j] == 'X' && check_connection_path(i, j, all) == 1
        && num_wall > 0 && rand() % 2 && num_wall >= 0){
            all->array_map[i][j] = '*';
            num_wall--;
            return (num_wall);
        }
        j++;
    }
    return (num_wall);
}

void imperfect_map(s_var *all)
{
    int i = 0;
    int j = 0;
    int num_wall = (num_walls(all) * 10) / 100;

    while (all->array_map[i] != NULL) {
        j = 0;
        num_wall = imperfect_map2(all, i, j, num_wall);
        i++;
    }
}
