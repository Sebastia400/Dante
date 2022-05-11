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

    typedef struct t_var {
        char **array_map;
        char **map_solved;
        int perfect;
        int solved;
        bool solution;
        int x;
        int y;
        int x_max;
        int y_max;
        int *directions;
    } s_var;
#endif
