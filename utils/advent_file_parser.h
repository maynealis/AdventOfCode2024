#ifndef ADVENT_FILE_PARSER_HH
#define ADVENT_FILE_PARSER_HH

#include <stdbool.h>

typedef struct DoubleIntArray
{
    unsigned int *first;
    unsigned int *second;
    unsigned int size_first;
    unsigned int size_second;
} DoubleIntArray;

bool ft_isspace(char c);
DoubleIntArray *create_double_int_array();
void parse_adv1(char *str, DoubleIntArray* double_array);

#endif