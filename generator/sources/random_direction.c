/*
** EPITECH PROJECT, 2022
** victor header
** File description:
** DANTE_GENE_BASIC_FUNC
*/

#include "./../includes/library.h"

void reset_direction(s_var *all)
{
    all->directions[0] = 0;
    all->directions[1] = 0;
    all->directions[2] = 0;
    all->directions[3] = 0;
}

void random_direction4(s_var *all, int i, int j, int sign)
{
    all->array_map[i + (1 * sign)][j] = 'o';
    all->array_map[i + (2 * sign)][j] = 'o';
}

void random_direction3(s_var *all, int i, int j, int sign)
{
    all->array_map[i][j + (1 * sign)] = 'o';
    all->array_map[i][j + (2 * sign)] = 'o';
}

void random_direction2(s_var *all, int i, int j, int rand_dir)
{
    switch (rand_dir) {
        case 0:
            random_direction3(all, i, j, 1);
            travel_map(all, i, j + 2);
            break;
        case 1:
            random_direction3(all, i, j, -1);
            travel_map(all, i, j - 2);
            break;
        case 2:
            random_direction4(all, i, j, 1);
            travel_map(all, i + 2, j);
            break;
        case 3:
            random_direction4(all, i, j, -1);
            travel_map(all, i - 2, j);
            break;
    }
}

void random_direction(s_var *all, int i, int j)
{
    int rand_dir = rand() % 4;
    int x = 0;

    while (all->directions[rand_dir] == 0 && x < 30) {
        rand_dir = rand() % 4;
        x++;
    }
    if (x < 30) {
        random_direction2(all, i, j, rand_dir);
    }
}
