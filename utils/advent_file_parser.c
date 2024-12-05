#include "read_file.h"
#include <stdlib.h>
#include "advent_file_parser.h"

bool ft_isspace(char c)
{
    if (c == ' ' || c == '\t' || c == '\v' || c == '\r' || c == '\f')
        return true;
    return false;
}

DoubleIntArray *create_double_int_array()
{
    DoubleIntArray *double_array = malloc(sizeof(DoubleIntArray));
    if (double_array == NULL)
        return NULL;
    return double_array;
}

void free_double_array(DoubleIntArray *double_array)
{
    if (double_array != NULL)
    {
        if (double_array->first != NULL)
            free(double_array->first);
        if (double_array->second != NULL)
            free(double_array->second);
        free(double_array);
        double_array = NULL;
    }
}

char add_number(DoubleIntArray* double_array, unsigned int first_num, unsigned int second_num, int size)
{
    unsigned int *new_first;
    unsigned int *new_second;

    new_first = realloc(double_array->first, size * sizeof(unsigned int));
    if (new_first == NULL)
    {
        free_double_array(double_array);
        return (0);
    }
    new_second = realloc(double_array->second, size * sizeof(unsigned int));
    if (new_second == NULL)
    {
        free_double_array(double_array);
        return (0);
    }
    double_array->first = new_first;
    double_array->second = new_second;
    double_array->first[size - 1] = first_num;
    double_array->second[size - 1] = second_num;
    return (1);
}

void parse_adv1(char *str, DoubleIntArray* double_array)
{
    int i;
    bool isFirst;
    int nline;
    unsigned int first_num;
    unsigned int second_num;

    i = 0;
    nline = 1;
    isFirst = true;
    first_num = 0;
    second_num = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <='9')
        {
            if(isFirst) 
                first_num = first_num * 10 + (str[i] - '0');
            else
                second_num = second_num * 10 + (str[i] - '0');
        }
        else if (ft_isspace(str[i]) && !ft_isspace(str[i-1]))
            isFirst = !isFirst;
        else if (str[i] == '\n')
        {
            isFirst = !isFirst;
            add_number(double_array, first_num, second_num, nline);
            nline++;
            first_num = 0;
            second_num = 0;
        }
        i++;
    }
    add_number(double_array, first_num, second_num, nline);
    double_array->size_first = nline;
    double_array->size_second = nline;
}