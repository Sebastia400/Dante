/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** Exercise myhunt page 1
*/

#include "./../includes/library.h"

int fs_open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd != -1)
        return (fd);
    else
        exit (84);
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

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_strcat(char *dest, char *src)
{
    char *temp = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src)) + 2);
    int i = 0;
    int n = 0;

    my_memset(temp, '\0', (my_strlen(dest) + my_strlen(src)) + 2);
    while (dest[i] != '\0') {
        temp[i] = dest[i];
        i++;
    }
    while (src[n] != '\0') {
        temp[i] = src[n];
        i++;
        n++;
    }
    temp[i] = '\0';
    return (temp);
}

char *my_strdup(char *str)
{
    char *result = calloc(my_strlen(str) + 1, sizeof(char));
    int i = 0;

    while (str[i] != '\0') {
        result[i] = str[i];
        i++;
    }
    result[i] = '\0';
    return (result);
}
