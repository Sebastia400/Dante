/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-victor.gonzalez
** File description:
** main.c
*/

#include "./../includes/library.h"

void func_save_temp(t_info_path *save_tmp, t_info_path *link)
{
    *save_tmp = *link;
    save_tmp->next = NULL;
}

void save_on_pointer(t_info_path *i, t_info_path *temp)
{
    t_info_path *next_ptr = i->next;
    *i = *temp;
    i->next = next_ptr;
}

void sort_linked_ext(s_var *all, t_info_path *i, t_info_path *j)
{
    t_info_path *save_tmp = malloc(sizeof(t_info_path));

    if (i->length > j->length) {
        func_save_temp(save_tmp, i);
        save_on_pointer(i, j);
        save_on_pointer(j, save_tmp);
    }
    free(save_tmp);
}

void sort_linked(s_var *all)
{
    t_info_path *i = all->path_solutions->next;
    t_info_path *j = all->path_solutions->next;

    while (i != NULL) {
        j = i;
        while (j != NULL) {
            sort_linked_ext(all, i, j);
            j = j->next;
        }
        i = i->next;
    }
}

void pop_up_linked_path(s_var *all, t_info_path *path)
{
    t_info_path *finalpath = all->path_solutions;
    t_info_path *tmp = malloc(sizeof(t_info_path));

    int i = 0;
    while (finalpath != NULL) {
        if (finalpath->next == path)
            finalpath->next = finalpath->next->next;
        else
            finalpath = finalpath->next;
    }
}
