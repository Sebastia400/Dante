/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-victor.gonzalez
** File description:
** main.c
*/

#include "./../includes/library.h"

void clean_travel(s_var *all)
{
    int i = 0;
    int j = 0;

    while (all->map_solved[i] != NULL) {
        j = 0;
        clean_travel_ext(all, i, j);
        i++;
    }
}

void clean_travel_2_ext(s_var *all, int i, int j)
{
    while (all->map_solved[i][j] != '\0') {
        if (all->map_solved[i][j] == '1' || all->map_solved[i][j] == 'B'
        || all->map_solved[i][j] == '2')
            all->map_solved[i][j] = 'o';
        j++;
    }
}

void clean_travel_2(s_var *all)
{
    int i = 0;
    int j = 0;

    while (all->map_solved[i] != NULL) {
        j = 0;
        clean_travel_2_ext(all, i, j);
        i++;
    }
}

void fill_array_ext(s_var *all, int i, int j)
{
    while (all->array_map[i][j] != '\0') {
        if (all->array_map[i][j] == '*')
            all->array_map[i][j] = '1';
        j++;
    }
}

void fill_array(s_var *all)
{
    int i = 0;
    int j = 0;

    while (all->array_map[i] != NULL) {
        j = 0;
        fill_array_ext(all, i, j);
        i++;
    }
}
