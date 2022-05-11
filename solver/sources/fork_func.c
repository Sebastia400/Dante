/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-victor.gonzalez
** File description:
** main.c
*/

#include "./../includes/library.h"

void save_bifurcation_ext(s_var *all, int x, int y)
{
    while (all->array_map[y][x] != '\0') {
        if (all->array_map[y][x] != 'X' && return_num(all, y, x) >= 2) {
            all->array_map[y][x] = 'B';
            create_bifurcations(all->bifurcations_ptr, x, y, 'B');
        }
        x++;
    }
}

void save_bifurcation(s_var *all)
{
    int x = 0;
    int y = 0;

    while (all->array_map[y] != NULL) {
        x = 0;
        save_bifurcation_ext(all, x, y);
        y++;
    }
}

void travel_commas_2(s_var *all, int i, int j);

void finished_commas(s_var *all, char **array_map, int i, int j)
{
    if (return_num(all, i, j) != 1) {
        all->j = j;
        all->i = i;
        all->solved = 1;
    }
}

void travel_commas(s_var *all, int i, int j)
{
    finished_commas(all, all->array_map, i, j);
    if (all->solved == 0 && all->array_map[i][j] == '*')
        all->array_map[i][j] = ',';
    if (!all->solved && all->array_map[i][j + 1] != '\0'
    && valid_char(all, all->array_map[i][j + 1]))
        travel_commas(all, i, j + 1);
    if (!all->solved && all->array_map[i + 1] != NULL
    && valid_char(all, all->array_map[i + 1][j]))
        travel_commas(all, i + 1, j);
    travel_commas_2(all, i, j);
}

void travel_commas_2(s_var *all, int i, int j)
{
    if (!all->solved && j > 0 && valid_char(all, all->array_map[i][j - 1]))
        travel_commas(all, i, j - 1);
    if (!all->solved && i > 0 && valid_char(all, all->array_map[i - 1][j]))
        travel_commas(all, i - 1, j);
}
