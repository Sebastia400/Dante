/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-victor.gonzalez
** File description:
** main.c
*/

#include "./../includes/library.h"

t_info_path *init_linked_path(int *information, t_info_files *prev)
{
    t_info_path *tmp = malloc(sizeof(t_info_path) * 1);
    tmp->length = information[0];
    tmp->prev_direction = information[1];
    tmp->distance_path += information[2];
    tmp->prev_pos_x = information[3];
    tmp->prev_pos_y = information[4];
    tmp->prev_distance = information[5] + information[2];
    tmp->pos_bif_x = information[6];
    tmp->pos_bif_y = information[7];
    tmp->prev = prev;
    tmp->next = NULL;
    return (tmp);
}

t_info_final_path *init_linked_final_path(t_info_path *path)
{
    t_info_final_path *tmp = malloc(sizeof(t_info_final_path) * 1);
    tmp->pos_bif_x = path->pos_bif_x;
    tmp->pos_bif_y = path->pos_bif_y;
    tmp->prev_pos_x = path->prev_pos_x;
    tmp->prev_pos_y = path->prev_pos_y;
    tmp->prev_distance = path->prev_distance;
    tmp->prev = path->prev;
    tmp->length = path->length;
    tmp->distance_path = path->distance_path;
    tmp->prev_direction = path->prev_direction;
    tmp->next = NULL;
    return (tmp);
}