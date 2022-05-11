/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-victor.gonzalez
** File description:
** main.c
*/

#include "./../includes/library.h"

void create_bifurcations(t_info_files *file, int i, int j, char bif_corner)
{
    t_info_files *tmp = file;
    int num = 0;
    while (tmp->next != NULL) {
        num++;
        tmp = tmp->next;
    }
    tmp->next = ini_linked_bifurcations(i, j, bif_corner, num);
}

int return_num(s_var *all, int i, int j)
{
    int num_bif = 0;

    if (all->array_map[i][j + 1] != '\0' &&
    valid_char(all, all->array_map[i][j + 1]) == 1)
        num_bif++;
    if (all->array_map[i + 1] != NULL &&
    valid_char(all, all->array_map[i + 1][j]) == 1)
        num_bif++;
    if (j > 0 && valid_char(all, all->array_map[i][j - 1]) == 1)
        num_bif++;
    if (i > 0 && valid_char(all, all->array_map[i - 1][j]) == 1)
        num_bif++;
    return (return_num2(all, num_bif, i, j));
}

int return_num2(s_var *all, int num_bif, int i, int j)
{
    if (j == all->y_max && i == all->x_max)
        return (3);
    if (i == 0 && j == 0)
        return (3);
    if (num_bif == 2) {
        if (j > 0 && all->array_map[i][j + 1] != '\0' &&
        valid_char(all, all->array_map[i][j + 1]) &&
        valid_char(all, all->array_map[i][j - 1]))
            return (0);
        if (i > 0 &&  all->array_map[i + 1] != NULL &&
        valid_char(all, all->array_map[i + 1][j]) &&
        valid_char(all, all->array_map[i - 1][j]))
            return (0);
    }
    return (num_bif);
}

bool save_bifurcation_2_ext(s_var *all, int x, int y)
{
    bool find = false;
    while (all->array_map[y][x] != '\0') {
        if (all->array_map[y][x] == '*' && return_num(all, y, x) == 1) {
            all->array_map[y][x] = ',';
            travel_commas(all, y, x);
            all->solved = 0;
            find = true;
        }
        x++;
    }
    return (find);
}

void save_bifurcation_2(s_var *all)
{
    int x = 0;
    int y = 0;
    bool find = true;

    while (find) {
        y = 0;
        while (all->array_map[y] != NULL) {
            x = 0;
            find = save_bifurcation_2_ext(all, x, y);
            y++;
        }
    }
}
