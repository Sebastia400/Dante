/*
** EPITECH PROJECT, 2022
** victor header
** File description:
** DANTE_GENE_BASIC_FUNC
*/

#include "./../includes/library.h"

void my_putchar(char letter)
{
    write(1, &letter, 1);
}

void my_putstr(char const *str)
{
    int len = 0;

    if (str) {
        len = strlen(str);
        if (len > 0)
            write(1, str, len);
    }
}

void print_array_strings(char **array)
{
    int i = 0;

    while (array[i] != NULL) {
        write(1, array[i], strlen(array[i]));
        if (array[i + 1] != NULL)
            my_putchar('\n');
        i++;
    }
}

void *my_memset(void *s, int c, int n)
{
    char *tmp = NULL;
    int	i = 0;

    tmp = s;
    i = 0;
    while (i < n)
        tmp[i++] = c;
    return (tmp);
}
