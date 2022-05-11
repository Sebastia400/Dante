/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-victor.gonzalez
** File description:
** main.c
*/

#include "./../includes/library.h"

void recursive_finished(s_var *all, char **array_map, int i, int j)
{
    if (array_map[i][j] == 'B') {
        all->j = j;
        all->i = i;
        all->solved = 1;
    }
}

void travel_map(s_var *all, int i, int j)
{
    all->distance++;
    recursive_finished(all, all->array_map, i, j);
    if (all->solved == 0 && all->array_map[i][j] == all->char_find)
        all->array_map[i][j] = all->set_route;
    if (!all->solved && all->array_map[i][j + 1] != '\0'
    && valid_char(all, all->array_map[i][j + 1]))
        travel_map(all, i, j + 1);
    if (!all->solved && all->array_map[i + 1] != NULL
    && valid_char(all, all->array_map[i + 1][j]))
        travel_map(all, i + 1, j);
    travel_map_2(all, i, j);
}

void travel_map_2(s_var *all, int i, int j)
{
    if (!all->solved && j > 0 && valid_char(all, all->array_map[i][j - 1]))
        travel_map(all, i, j - 1);
    if (!all->solved && i > 0 && valid_char(all, all->array_map[i - 1][j]))
        travel_map(all, i - 1, j);
    else if (!all->solved)
        all->distance--;
}

void travel_map_finish(s_var *all, int i, int j)
{
    all->distance++;
    recursive_finished(all, all->map_solved, i, j);
    if (all->solved == 0 && all->map_solved[i][j] == all->char_find)
        all->map_solved[i][j] = 'o';
    if (!all->solved && all->map_solved[i][j + 1] != '\0'
    && valid_char(all, all->map_solved[i][j + 1]))
        travel_map_finish(all, i, j + 1);
    if (!all->solved && all->map_solved[i + 1] != NULL
    && valid_char(all, all->map_solved[i + 1][j]))
        travel_map_finish(all, i + 1, j);
    travel_map_finish_2(all, i, j);
}

void travel_map_finish_2(s_var *all, int i, int j)
{
    if (!all->solved && j > 0 && valid_char(all, all->map_solved[i][j - 1]))
        travel_map_finish(all, i, j - 1);
    if (!all->solved && i > 0 && valid_char(all, all->map_solved[i - 1][j]))
        travel_map_finish(all, i - 1, j);
    else if (!all->solved)
        all->distance--;
}
