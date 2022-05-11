/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-victor.gonzalez
** File description:
** main.c
*/

#include "./../includes/library.h"

char **save_matrix(s_var *all, char **matrix)
{
    int i = 0;
    char **temp = calloc(all->x_max * 2, sizeof(char *));

    while (matrix[i] != NULL) {
        temp[i] = my_strdup(matrix[i]);
        i++;
    }
    temp[i] = NULL;
    return (temp);
}

char **save_word(char *arraytext, char separator, char *filepath)
{
    int len = 0;
    int i = 0;
    int k = 0;
    int j = 0;
    char **sentences;

    sentences = calloc(quantity_sentences(size_text(filepath),
    arraytext, '\n') * 2, sizeof(char *));
    while (i < size_text(filepath)) {
        len = len_sentence(arraytext, separator);
        sentences[j] = calloc(len * 2 + 10, sizeof(char));
        k = 0;
        while (arraytext[i] != separator && arraytext[i] != '\0' &&
        arraytext[i] != '\n')
            sentences[j][k++] = arraytext[i++];
        j++;
        i++;
    }
    sentences[j] = NULL;
    return (sentences);
}

char *save_text(int fd, char *filepath)
{
    int i = 0;
    int size = 0;
    long max_size = 0;
    char *arraytext;

    size = size_text(filepath);
    arraytext = malloc(sizeof(char) * size + 1);
    memset(arraytext, '\0', size + 1);
    read(fd, arraytext, size);
    return (arraytext);
}

void save_maps(s_var *all, char *filename)
{
    int fd = open(filename, O_RDONLY);

    all->map = save_text(fd, filename);
    all->array_map = save_word(all->map, '\n', filename);
    all->map_solved = save_word(all->map, '\n', filename);
    all->x_max = quantity_sentences(size_text(filename), all->map, '\n') - 1;
    all->y_max = my_strlen(all->array_map[0]) - 1;
    if (all->y_max > 2000 && all->x_max > 2000)
        exit(0);
}
