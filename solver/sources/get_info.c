/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-victor.gonzalez
** File description:
** main.c
*/

#include "./../includes/library.h"

t_info_files *get_bif_pointer(t_info_files *bifurcations_ptr, int i, int j)
{
    t_info_files *tmp = bifurcations_ptr;

    while (tmp != NULL) {
        if (tmp->bif_pos_x == j && tmp->bif_pos_y == i)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

t_info_final_path *get_path(t_info_final_path *path, int i, int j)
{
    t_info_final_path *tmp = path->next;
    t_info_final_path *path_2 = malloc(sizeof(t_info_final_path));

    while (tmp != NULL) {
        if (tmp->pos_bif_x == j && tmp->pos_bif_y == i)
            path_2 = tmp;
        tmp = tmp->next;
    }
    return (path_2);
}

void set_directions_false(s_var *all)
{
    t_info_files *tmp = all->bifurcations_ptr;

    while (tmp != NULL) {
        tmp->checked_right = false;
        tmp->checked_left = false;
        tmp->checked_up = false;
        tmp->checked_down = false;
        tmp = tmp->next;
    }
}

t_info_path *get_short_path(s_var *all)
{

    t_info_path *path = all->path_solutions;
    path = path->next;
    if (path->pos_bif_x == all->y_max && path->pos_bif_y == all->x_max)
        all->solved = 1;
    return (path);
}

t_info_final_path *get_last_linked_pos(s_var *all)
{
    t_info_final_path *tmp = all->final_path;

    while (tmp->next != NULL)
        tmp = tmp->next;
    return (tmp);
}
