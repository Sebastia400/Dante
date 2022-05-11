/*
** EPITECH PROJECT, 2022
** victor header
** File description:
** DANTE_GENE_BASIC_FUNC
*/

#include "./../includes/library.h"

void print_possible_directions(s_var *all, int i, int j)
{
    check_horitzontal(all, i, j);
    check_vertical(all, i, j);
}

void travel_map(s_var *all, int i, int j)
{
    reset_direction(all);
    print_possible_directions(all, i, j);
    if (!all->solved && all->array_map[i][j + 2] != '\0' &&
    all->array_map[i][j + 2] != '\n' && all->array_map[i][j + 2] == '1')
        all->directions[0] = 1;
    if (!all->solved && j > 1 && all->array_map[i][j - 2] == '1')
        all->directions[1] = 1;
    if (!all->solved && all->array_map[i + 2] != NULL
    && all->array_map[i + 2][j] == '1')
        all->directions[2] = 1;
    if (!all->solved && i > 1 && all->array_map[i - 2][j] == '1')
        all->directions[3] = 1;
    random_direction(all, i, j);
}

void find_1_2(s_var *all, int i, int j)
{
    if (all->array_map[i][j] == 'o' && !(j % 2))
        travel_map(all, i, j);
}

void find_1(s_var *all)
{
    int i = 0;
    int j = 0;

    while (all->array_map[i] != NULL) {
        j = 0;
        while (all->array_map[i][j] != '\0' && !(i % 2)) {
            find_1_2(all, i, j);
            j++;
        }
        i++;
    }
}
