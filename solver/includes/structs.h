/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** fgfghgf
*/

#ifndef STRUCTS_H_
    #define STRUCTS_H_
    #include <time.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>

    typedef struct s_info_final_path {
        int length;
        int pos_bif_x;
        int pos_bif_y;
        int distance_path;
        int prev_distance;
        int prev_direction;
        int prev_pos_x;
        int prev_pos_y;
        struct s_info_files *prev;
        struct s_info_final_path *next;
    } t_info_final_path;

    typedef struct s_info_path {
        int length;
        int pos_bif_x;
        int pos_bif_y;
        int distance_path;
        int prev_distance;
        int prev_direction;
        int prev_pos_x;
        int prev_pos_y;
        struct s_info_files *prev;
        struct s_info_path *next;
    } t_info_path;

    typedef struct s_info_files {
        int num;
        int bif_pos_x;
        int bif_pos_y;
        char bif_corner;
        int total_distance;
        bool fork_checked;
        int dis_right;
        int pos_fork_right_x;
        int pos_fork_right_y;
        int dis_left;
        int pos_fork_left_x;
        int pos_fork_left_y;
        int dis_up;
        int pos_fork_up_x;
        int pos_fork_up_y;
        int dis_down;
        int pos_fork_down_x;
        int pos_fork_down_y;
        bool checked_right;
        bool checked_left;
        bool checked_up;
        bool checked_down;
        bool map_with_solution;
        struct s_info_files *right;
        struct s_info_files *left;
        struct s_info_files *up;
        struct s_info_files *down;
        struct s_info_files *next;
    } t_info_files;

    typedef struct t_var {
        char **array_map;
        char **map_solved;
        char *map;
        bool imperfect_maze;
        int distance;
        bool solution;
        int i;
        int j;
        int y_max;
        int x_max;
        int solved;
        int priority;
        int direction;
        char char_find;
        char set_route;
        t_info_path *path_solutions;
        t_info_final_path *final_path;
        t_info_files *bifurcations_ptr;
    } s_var;
#endif
