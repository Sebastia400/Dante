
/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-victor.gonzalez
** File description:
** main.c
*/

#include "./../includes/library.h"

void manage_check_sides(s_var *all, t_info_files *tmp, int distance_prev)
{
    check_right_path(all, tmp, distance_prev);
    check_left_path(all, tmp, distance_prev);
    check_up_path(all, tmp, distance_prev);
    check_down_path(all, tmp, distance_prev);
    tmp->fork_checked = TRUE;
}

void check_right_path(s_var *all, t_info_files *tmp, int prev_distance)
{
    int distance = 0;
    int distance_path = 0;
    int *information = malloc(sizeof(int) * 8);

    if (tmp->right != NULL && !all->solved && tmp->fork_checked == FALSE) {
        distance = tmp->dis_right + tmp->right->total_distance + prev_distance;
        distance_path += tmp->dis_right;
        if (distance_path != 0 && tmp->right->fork_checked != TRUE) {
            information[0] = distance;
            information[1] = 0;
            information[2] = distance_path;
            information[3] = tmp->bif_pos_x;
            information[4] = tmp->bif_pos_y;
            information[5] = prev_distance;
            information[6] = tmp->pos_fork_right_x;
            information[7] = tmp->pos_fork_right_y;
            save_path(all, information, tmp->right);
        }
    }
    tmp->checked_right = TRUE;
}

void check_left_path(s_var *all, t_info_files *tmp, int prev_distance)
{
    int distance = 0;
    int distance_path = 0;
    int *information = malloc(sizeof(int) * 8);

    if (tmp->left != NULL && !all->solved && tmp->fork_checked == FALSE) {
        distance = tmp->dis_left + tmp->left->total_distance + prev_distance;
        distance_path += tmp->dis_left;
        if (distance_path != 0 && tmp->left->fork_checked != TRUE) {
            information[0] = distance;
            information[1] = 1;
            information[2] = distance_path;
            information[3] = tmp->bif_pos_x;
            information[4] = tmp->bif_pos_y;
            information[5] = prev_distance;
            information[6] = tmp->pos_fork_left_x;
            information[7] = tmp->pos_fork_left_y;
            save_path(all, information, tmp->left);
        }
    }
    tmp->checked_left = TRUE;
}

void check_up_path(s_var *all, t_info_files *tmp, int prev_distance)
{
    int distance = 0;
    int distance_path = 0;
    int *information = malloc(sizeof(int) * 8);

    if (tmp->up != NULL && !all->solved && tmp->fork_checked == FALSE) {
        distance = tmp->dis_up + tmp->up->total_distance + prev_distance;
        distance_path += tmp->dis_up;
        if (distance_path != 0 && tmp->up->fork_checked != TRUE) {
            information[0] = distance;
            information[1] = 2;
            information[2] = distance_path;
            information[3] = tmp->bif_pos_x;
            information[4] = tmp->bif_pos_y;
            information[5] = prev_distance;
            information[6] = tmp->pos_fork_up_x;
            information[7] = tmp->pos_fork_up_y;
            save_path(all, information, tmp->up);
        }
    }
    tmp->checked_up = TRUE;
}

void check_down_path(s_var *all, t_info_files *tmp, int prev_distance)
{
    int distance = 0;
    int distance_path = 0;
    int *information = malloc(sizeof(int) * 8);

    if (tmp->down != NULL && !all->solved && tmp->fork_checked == FALSE) {
        distance = tmp->dis_down + tmp->down->total_distance + prev_distance;
        distance_path += tmp->dis_down;
        if (distance_path != 0 && tmp->down->fork_checked != TRUE) {
            information[0] = distance;
            information[1] = 3;
            information[2] = distance_path;
            information[3] = tmp->bif_pos_x;
            information[4] = tmp->bif_pos_y;
            information[5] = prev_distance;
            information[6] = tmp->pos_fork_down_x;
            information[7] = tmp->pos_fork_down_y;
            save_path(all, information, tmp->down);
        }
    }
    tmp->checked_down = TRUE;
}
