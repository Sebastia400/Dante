/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-victor.gonzalez
** File description:
** main.c
*/

#include "./../includes/library.h"

void conect_right_bif(s_var *all, t_info_files *tmp, int i, int j)
{
    if (tmp->checked_right == FALSE && j < all->y_max &&
    all->array_map[i][j + 1] != 'X') {
        all->solved = 0;
        travel_map(all, i, j + 1);
        if (all->array_map[all->i][all->j] == 'B') {
            tmp->right =
            get_bif_pointer(all->bifurcations_ptr, all->i, all->j);
            tmp->dis_right = all->distance;
            tmp->pos_fork_right_x = all->j;
            tmp->pos_fork_right_y = all->i;
        } else
            tmp->right = NULL;
        tmp->checked_right = TRUE;
    }
}

void conect_left_bif(s_var *all, t_info_files *tmp, int i, int j)
{
    if (tmp->checked_left == FALSE && j > 0
    && all->array_map[i][j - 1] != 'X') {
        all->solved = 0;
        travel_map(all, i, j - 1);
        if (all->array_map[all->i][all->j] == 'B') {
            tmp->left = get_bif_pointer(all->bifurcations_ptr, all->i, all->j);
            tmp->dis_left = all->distance;
            tmp->pos_fork_left_x = all->j;
            tmp->pos_fork_left_y = all->i;
        } else
            tmp->left = NULL;
        tmp->checked_left = TRUE;
    }
}

void conect_down_bif(s_var *all, t_info_files *tmp, int i, int j)
{
    if (tmp->checked_down == FALSE && i < all->x_max
    && all->array_map[i + 1][j] != 'X') {
        all->solved = 0;
        travel_map(all, i + 1, j);
        if (all->array_map[all->i][all->j] == 'B') {
            tmp->down = get_bif_pointer(all->bifurcations_ptr, all->i, all->j);
            tmp->dis_down = all->distance;
            tmp->pos_fork_down_x = all->j;
            tmp->pos_fork_down_y = all->i;
        } else
            tmp->down = NULL;
        tmp->checked_down = TRUE;
    }
}

void conect_up_bif(s_var *all, t_info_files *tmp, int i, int j)
{
    if (tmp->checked_up == FALSE && i > 0
    && all->array_map[i - 1][j] != 'X') {
        all->solved = 0;
        travel_map(all, i - 1, j);
        if (all->array_map[all->i][all->j] == 'B') {
            tmp->up = get_bif_pointer(all->bifurcations_ptr, all->i, all->j);
            tmp->dis_up = all->distance;
            tmp->pos_fork_up_x = all->j;
            tmp->pos_fork_up_y = all->i;
        } else
            tmp->up = NULL;
        tmp->checked_up = TRUE;
    }
}

void check_sides(s_var *all, int i, int j)
{
    t_info_files *tmp = all->bifurcations_ptr->next;
    while (tmp != NULL) {
        i = tmp->bif_pos_y;
        j = tmp->bif_pos_x;
        all->j = tmp->bif_pos_x;
        all->i = tmp->bif_pos_y;
        all->array_map[i][j] = '2';
        all->distance = 0;
        conect_right_bif(all, tmp, i, j);
        all->distance = 0;
        conect_left_bif(all, tmp, i, j);
        all->distance = 0;
        conect_down_bif(all, tmp, i, j);
        all->distance = 0;
        conect_up_bif(all, tmp, i, j);
        all->distance = 0;
        delete_hor(all, tmp->bif_pos_y, tmp->bif_pos_x);
        delete_vert(all, tmp->bif_pos_y, tmp->bif_pos_x);
        all->array_map[i][j] = 'B';
        tmp = tmp->next;
    }
    fill_array(all);
}
