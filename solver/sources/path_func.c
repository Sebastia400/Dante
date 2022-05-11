/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-victor.gonzalez
** File description:
** main.c
*/

#include "./../includes/library.h"

void draw_final_map2(s_var *all, t_info_final_path *tmp)
{
    all->map_solved[all->i][all->j] = 'o';
    switch (tmp->prev_direction) {
        case 0:
            travel_map_finish(all, all->i, all->j - 1);
            break;
        case 1:
            travel_map_finish(all, all->i, all->j + 1);
            break;
        case 2:
            travel_map_finish(all, all->i + 1, all->j);
            break;
        case 3:
            travel_map_finish(all, all->i - 1, all->j);
            break;
    }
}

void draw_final_map(s_var *all)
{
    t_info_final_path *tmp = all->final_path;

    all->j = get_last_linked_pos(all)->pos_bif_x;
    all->i = get_last_linked_pos(all)->pos_bif_y;
    all->solved = 0;
    while (all->i != 0 || all->j != 0) {
        draw_final_map2(all, tmp);
        tmp = get_path(all->final_path, all->i, all->j);
        all->solved = 0;
    }
    all->solved = 1;
    all->map_solved[0][0] = 'o';
    if (all->x_max > 0 && all->map_solved[all->x_max - 1][all->y_max] == 'B')
        all->map_solved[all->x_max - 1][all->y_max] = 'o';
    if (all->y_max > 0 && all->map_solved[all->x_max][all->y_max - 1] == 'B')
        all->map_solved[all->x_max][all->y_max - 1] = 'o';
    clean_travel(all);
}

void external_save_path(s_var *all, t_info_path *path, int distance_prev)
{
    int biff = 0;

    while (!all->solved) {
        manage_check_sides(all, path->prev, distance_prev);
        save_final_path(all, path);
        pop_up_linked_path(all, path);
        sort_linked(all);
        path = get_short_path(all);
        distance_prev = path->prev_distance;
        biff++;
    }
}

void save_path_linked(s_var *all)
{
    int distance_prev = 0;
    t_info_files *tmp = all->bifurcations_ptr->next;
    t_info_path *path = all->path_solutions;

    all->solved = 0;
    manage_check_sides(all, tmp, distance_prev);
    sort_linked(all);
    path = get_short_path(all);
    distance_prev = path->distance_path;
    external_save_path(all, path, distance_prev);
    path = get_short_path(all);
    save_final_path(all, path);
    draw_final_map(all);
}
