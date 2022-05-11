/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-victor.gonzalez
** File description:
** main.c
*/

#include "./../includes/library.h"

void clean_travel_ext(s_var *all, int i, int j)
{
    while (all->map_solved[i][j] != '\0') {
        if (valid_char(all, all->map_solved[i][j])
        || all->map_solved[i][j] == '1' || all->map_solved[i][j] == ',')
            all->map_solved[i][j] = '*';
        j++;
    }
}
