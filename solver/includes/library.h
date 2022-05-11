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

void clean_travel_ext(s_var *all, int i, int j);
int return_num(s_var *all, int i, int j);
void save_path(s_var *all, int *information, t_info_files *prev);
void save_path_linked(s_var *all);
void fill_array(s_var *all);
int my_strlen(char const *str);
char *my_strcat(char *dest, char *src);
int find_path(s_var *all, char *movemnts, int distance, int *prev_pos);
int valid_char(s_var *all, char n);
void clean_travel_2(s_var *all);
void travel_map_finish(s_var *all, int i, int j);
void travel_map_finish_2(s_var *all, int i, int j);
void my_putchar(char letter);
void my_putstr(char const *str);
char *my_strdup(char *str);
int my_strlen(char const *str);
void save_distance_bifuration(s_var *all);
void save_path(s_var *all, int *information, t_info_files *prev);
void save_final_path(s_var *all, t_info_path *path);
void manage_check_sides(s_var *all, t_info_files *tmp, int distance_prev);
void check_right_path(s_var *all, t_info_files *tmp, int prev_distance);
void check_left_path(s_var *all, t_info_files *tmp, int prev_distance);
void check_up_path(s_var *all, t_info_files *tmp, int prev_distance);
void check_down_path(s_var *all, t_info_files *tmp, int prev_distance);
int check_num_forks_near(t_info_files *fork);
void check_imperfect_maze(s_var *all);
int map_without_solution(s_var *all);
t_info_files *get_bif_pointer(t_info_files *bifurcations_ptr, int i,
int j);
t_info_path *get_short_path(s_var *all);
void set_directions_false(s_var *all);
t_info_final_path *get_path(t_info_final_path *path, int i, int j);
t_info_final_path *get_last_linked_pos(s_var *all);
void conect_right_bif(s_var *all, t_info_files *tmp, int i, int j);
void conect_left_bif(s_var *all, t_info_files *tmp, int i, int j);
void conect_down_bif(s_var *all, t_info_files *tmp, int i, int j);
void conect_up_bif(s_var *all, t_info_files *tmp, int i, int j);
void check_sides(s_var *all, int i, int j);
void create_bifurcations(t_info_files *file, int i, int j, char bif_corner);
int return_num(s_var *all, int i, int j);
int return_num2(s_var *all, int num_bif, int i, int j);
void save_bifurcation(s_var *all);
void save_bifurcation_2(s_var *all);
void func_save_temp(t_info_path *save_tmp, t_info_path *link);
void save_on_pointer(t_info_path *i, t_info_path *temp);
void sort_linked(s_var *all);
void pop_up_linked_path(s_var *all, t_info_path *path);
t_info_files *ini_linked_bifurcations(int i, int j, char bif_corner,
int num);
t_info_files *init_struc_bifurcations(void);
s_var *init_struct(void);
t_info_path *init_struct_path(void);
t_info_final_path *init_struct_final_path(void);
t_info_path *init_linked_path(int *information, t_info_files *prev);
t_info_final_path *init_linked_final_path(t_info_path *path);
void print_array_strings(char **array, int ini, int x_max);
void print_no_solution(void);
void print_solved(void);
void red(void);
void yellow(void);
void green(void);
void blue(void);
void reset_color (void);
void clean_travel(s_var *all);
void recursive_finished(s_var *all, char **array_map, int i, int j);
void travel_map(s_var *all, int i, int j);
void travel_map_2(s_var *all, int i, int j);
int go_horitzontal(s_var *all, int i1, int j1, int incre);
int go_vertical(s_var *all, int i1, int j1, int incre);
char *save_text(int fd, char *filepath);
char **save_word(char *arraytext, char separator, char *filepath);
char **save_matrix(s_var *all, char **matrix);
void save_maps(s_var *all, char *filename);
int size_text(char *filepath);
int quantity_sentences(int size_text, char *str, char delimiter);
int len_sentence(char *arraytext, char delimiter);
int fs_open_file(char const *filepath);
void *my_memset(void *s, int c, int n);
char *save_text(int fd, char *filepath);
char **save_word(char *arraytext, char separator, char *filepath);
void travel_map(s_var *all, int i, int j);
void delete_hor(s_var *all, int pos_i, int pos_j);
void delete_vert(s_var *all, int pos_i, int pos_j);
void travel_commas(s_var *all, int i, int j);
#endif
