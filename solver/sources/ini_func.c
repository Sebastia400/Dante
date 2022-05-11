/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-victor.gonzalez
** File description:
** main.c
*/

#include "./../includes/library.h"

t_info_files *ini_linked_bifurcations(int i, int j, char bif_corner, int num)
{
    t_info_files *file = malloc(sizeof(t_info_files) * 1);
    file->num = num;
    file->bif_pos_x = i;
    file->bif_pos_y = j;
    file->bif_corner = bif_corner;
    file->checked_up = false;
    file->checked_down = false;
    file->checked_right = false;
    file->checked_left = false;
    file->fork_checked = false;
    file->up = NULL;
    file->down = NULL;
    file->right = NULL;
    file->left = NULL;
    file->next = NULL;
    return file;
}

t_info_files *init_struc_bifurcations(void)
{
    t_info_files *res = malloc(sizeof(t_info_files));
    res->bif_pos_x = 0;
    res->bif_pos_y = 0;
    res->checked_up = false;
    res->checked_down = false;
    res->checked_right = false;
    res->checked_left = false;
    res->fork_checked = false;
    res->up = NULL;
    res->down = NULL;
    res->right = NULL;
    res->left = NULL;
    res->next = NULL;
    return res;
}

s_var *init_struct(void)
{
    s_var *all = malloc(sizeof(s_var) * 1);
    all->map = NULL;
    all->bifurcations_ptr = init_struc_bifurcations();
    all->path_solutions = init_struct_path();
    all->final_path = init_struct_final_path();
    all->solved = 0;
    all->direction = 0;
    all->char_find = '*';
    all->set_route = '1';
    return (all);
}

t_info_path *init_struct_path(void)
{
    t_info_path *tmp = malloc(sizeof(t_info_path));
    tmp->prev = NULL;
    tmp->prev_direction = 0;
    tmp->length = 0;
    tmp->next = NULL;
    return (tmp);
}

t_info_final_path *init_struct_final_path(void)
{
    t_info_final_path *tmp = malloc(sizeof(t_info_final_path));
    tmp->prev = NULL;
    tmp->prev_direction = 0;
    tmp->length = 0;
    tmp->next = NULL;
    return (tmp);
}