/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** Exercise myhunt page 1
*/

#include "./../includes/library.h"

s_var *init_struct(void)
{
    s_var *all = malloc(sizeof(s_var) * 1);
    all->directions = malloc(sizeof(int) * 4);
    all->perfect = 1;

    return (all);
}
