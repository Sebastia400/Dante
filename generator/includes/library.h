/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** lib my_hunterexercise
*/

#ifndef LIBRAY_H_
    #define LIBRAY_H_
    #include <string.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <stddef.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <ctype.h>
    #include "./structs.h"
    #include <math.h>
    #include <ncurses.h>

void my_putchar(char letter);
void my_putstr(char const *str);
void print_array_strings(char **array);
void *my_memset(void *s, int c, int n);
s_var *init_struct(void);
void fill_map_borders(s_var *all);
void fill_map_borders_1(s_var *all);
void fill_map_borders_2(s_var *all);
void print_possible_directions(s_var *all, int i, int j);
void travel_map(s_var *all, int i, int j);
void find_1(s_var *all);
void save_map(s_var *all, int x, int y);
void clean_map(s_var *all);
int check_connection_path(int i, int j, s_var *all);
void imperfect_map(s_var *all);
void get_arguments(int ac, char **argv, s_var *all);
void check_horitzontal(s_var *all, int i, int j);
void check_vertical(s_var *all, int i, int j);
void reset_direction(s_var *all);
void random_direction(s_var *all, int i, int j);
#endif
