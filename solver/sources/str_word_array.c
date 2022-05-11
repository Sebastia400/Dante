/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** Exercise myhunt page 1
*/

#include "./../includes/library.h"

int size_text(char *filepath)
{
    struct stat buf;
    stat(filepath, &buf);
    return (buf.st_size);
}

int quantity_sentences(int size_text, char *str, char delimiter)
{
    int i = 1;
    int num_sentences = 1;

    while (i < size_text) {
        if (str[i] == delimiter || str[i] == '\0')
            num_sentences++;
        i++;
    } return (num_sentences);
}

int len_sentence(char *arraytext, char delimiter)
{
    int i = 0;
    while (arraytext[i] != '\0' && arraytext[i] != delimiter)
        i++;
    return (i);
}
