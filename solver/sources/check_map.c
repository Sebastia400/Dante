/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-victor.gonzalez
** File description:
** main.c
*/

#include "./../includes/library.h"

int check_num_forks_near(t_info_files *fork)
{
    int num = 0;

    if (fork->right != NULL)
        num++;
    if (fork->left != NULL)
        num++;
    if (fork->up != NULL)
        num++;
    if (fork->down != NULL)
        num++;
    return num;
}

void check_imperfect_maze(s_var *all)
{
    t_info_files *tmp = all->bifurcations_ptr->next;

    while (tmp != NULL) {
        if (check_num_forks_near(tmp) >= 3)
            all->imperfect_maze = TRUE;
        tmp = tmp->next;
    }
}

int map_without_solution(s_var *all)
{
    all->array_map[all->x_max][all->y_max] = 'B';
    travel_map(all, 0, 0);
    if (all->solved == 1) {
        all->i = 0;
        all->j = 0;
        all->solved = 0;
        all->solution = TRUE;
        return (0);
    } else {
        if (all->array_map[0][0] != '\0' && all->array_map[0][0] == 'B')
            all->solution = FALSE;
        return (1);
    }
}
