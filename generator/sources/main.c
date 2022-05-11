/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** Exercise myhunt page 1
*/

#include "./../includes/library.h"

void check_horitzontal2(s_var *all, int i, int j)
{
    if (j > 1 && (all->array_map[i][j - 2] == '*'
    || all->array_map[i][j - 2] == '1') && all->array_map[i][j - 1] != 'o') {
        if (i > 1 && all->array_map[i - 2][j] == 'o'
        && all->array_map[i + 2] != NULL && all->array_map[i + 2][j] == 'o')
            all->array_map[i + 1][j - 1] = 'x';
        else {
            all->array_map[i][j - 1] = '1';
            all->array_map[i][j - 2] = '1';
        }
    }
}

void check_horitzontal(s_var *all, int i, int j)
{
    if (all->array_map[i][j + 2] != '\0' && (all->array_map[i][j + 2] == '*'
    || all->array_map[i][j + 2] == '1') && all->array_map[i][j + 1] != 'o') {
        if (i > 1 && all->array_map[i - 2][j] == 'o'
        && all->array_map[i + 2] != NULL && all->array_map[i + 2][j] == 'o')
            all->array_map[i + 1][j + 1] = 'x';
        else {
            all->array_map[i][j + 1] = '1';
            all->array_map[i][j + 2] = '1';
        }
    }
    check_horitzontal2(all, i , j);
}

void get_arguments(int ac, char **argv, s_var *all)
{
    if (ac > 3) {
        if (strcmp(argv[3], "perfect") == 0)
            all->perfect = 0;
    }
    if (all->perfect == 1)
        imperfect_map(all);
}

int main(int argc, char **argv)
{
    char **temp = NULL;

    srand(time(NULL));
    s_var *all = init_struct();
    all->x_max = atoi(argv[2]);
    all->y_max = atoi(argv[1]);
    save_map(all, all->x_max, all->y_max);
    travel_map(all, 0, 0);
    find_1(all);
    fill_map_borders(all);
    clean_map(all);
    get_arguments(argc, argv, all);
    print_array_strings(all->array_map);
    return (0);
}
