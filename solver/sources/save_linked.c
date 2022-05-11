/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-victor.gonzalez
** File description:
** main.c
*/

#include "./../includes/library.h"

void save_distance_bifuration(s_var *all)
{
    t_info_files *tmp = all->bifurcations_ptr->next;

    while (tmp != NULL) {
        tmp->total_distance = ((all->x_max - tmp->bif_pos_x) +
        (all->y_max - tmp->bif_pos_y));
        tmp = tmp->next;
    }
}

void save_path(s_var *all, int *information, t_info_files *prev)
{
    t_info_path *tmp = all->path_solutions;

    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = init_linked_path(information, prev);
}

void save_final_path(s_var *all, t_info_path *path)
{
    t_info_final_path *tmp = all->final_path;

    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = init_linked_final_path(path);
}
