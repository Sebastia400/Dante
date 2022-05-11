/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-victor.gonzalez
** File description:
** main.c
*/

#include "./../includes/library.h"

void dante_solver(s_var *all, char *argv)
{
    int i = 0;
    int j = 0;
    char **temp_map = NULL;

    if (!map_without_solution(all)) {
        all->array_map = save_matrix(all, all->map_solved);
        save_bifurcation_2(all);
        save_bifurcation(all);
        all->map_solved = save_matrix(all, all->array_map);
        save_distance_bifuration(all);
        check_sides(all, i, j);
    }
}

int valid_char(s_var *all, char n)
{
    if (n == '*' || n == 'B'
    || n == '.')
        return (1);
    return (0);
}

void perfect_imperfect(s_var *all)
{
    if (all->imperfect_maze == TRUE) {
        save_path_linked(all);
    } else {
        all->map_solved = save_matrix(all, all->array_map);
        clean_travel_2(all);
        clean_travel(all);
    }
}

void result_solution(s_var *all)
{
    if (all->x_max > 0 && all->map_solved[all->x_max - 1][all->y_max] == 'o' &&
    all->y_max > 0 && all->map_solved[all->x_max][all->y_max - 1] == 'o')
        all->map_solved[all->x_max - 1][all->y_max] = '*';
    if (all->x_max > 0 && all->map_solved[all->x_max - 1][all->y_max] == '*' &&
    (all->map_solved[all->x_max][all->y_max - 1] != 'o'
    || all->map_solved[all->x_max][all->y_max - 1] == 'X'))
        all->map_solved[all->x_max - 1][all->y_max] = 'o';
    if (all->solution == TRUE)
        print_array_strings(all->map_solved, 0, all->x_max);
    else
        my_putstr("no solution found");
}

int main(int argc, char **argv)
{
    int i = 0;
    s_var *all = init_struct();

    if (argc == 2 && open(argv[1], O_RDONLY) != -1 && size_text(argv[1]) > 0) {
        save_maps(all, argv[1]);
        dante_solver(all, argv[1]);
        check_imperfect_maze(all);
        perfect_imperfect(all);
        result_solution(all);
        free(all->array_map);
        return (0);
    } else
        return (84);
    return (0);
}
