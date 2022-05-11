/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-victor.gonzalez
** File description:
** main.c
*/

#include "./../includes/library.h"

int go_horitzontal(s_var *all, int i1, int j1, int incre)
{
    int x = 0;
    int i = i1;
    int j = j1;

    while (all->map_solved[i][j + incre] != '\0'
    && all->map_solved[i][j + incre] == '1') {
        all->map_solved[i][j + incre] = 'o';
        x++;
        j += incre;
    } return (x);
}

int go_vertical(s_var *all, int i1, int j1, int incre)
{
    int x = 0;
    int i = i1;
    int j = j1;

    while (i >= 0 && all->map_solved[i + incre] != NULL
    && all->map_solved[i + incre][j] == '1') {
        all->map_solved[i + incre][j] = 'o';
        x++;
        i += incre;
    } return (x);
}
