#include <stdlib.h> // For malloc, free and realloc
#include "advent_file_parser.h"

// TODO: put this in another generic file
bool ft_isspace(char c)
{
    if (c == ' ' || c == '\t' || c == '\v' || c == '\r' || c == '\f')
        return true;
    return false;
}

/**
 * @brief Creates a new DoubleIntArray structure.
 *
 * Allocates memory for a DoubleIntArray. This structure is used to store 
 * two dynamically allocated arrays of integers.
 *
 * @return A pointer to the newly created DoubleIntArray, 
 *         or NULL if memory allocation fails.
 */
DoubleIntArray *create_double_int_array()
{
    DoubleIntArray *double_array = malloc(sizeof(DoubleIntArray));
    if (double_array == NULL)
        return NULL;
    return double_array;
}

/**
 * @brief Frees the memory allocated for a DoubleIntArray.
 *
 * This function releases the memory allocated for the two arrays 
 * within the DoubleIntArray structure as well as the structure itself.
 *
 * @param double_array Pointer to the DoubleIntArray to free. If NULL, the function does nothing.
 */
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

/**
 * @brief Adds a pair of numbers to the DoubleIntArray structure.
 *
 * This function reallocates memory for the arrays within the DoubleIntArray
 * to accommodate a new pair of numbers and assigns the given values to the
 * newly created elements.
 *
 * @param double_array Pointer to the DoubleIntArray structure.
 * @param first_num The first number to add to the `first` array.
 * @param second_num The second number to add to the `second` array.
 * @param size The new size of the arrays after adding the numbers.
 * @return 1 if the operation succeeds, 0 if memory allocation fails.
 */
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

/**
 * @brief Parses input data into a DoubleIntArray structure.
 *
 * This function reads a string containing pairs of integers separated by 
 * whitespace or newlines. It populates the `first` and `second` arrays 
 * within the DoubleIntArray with the parsed integers. It handles edge 
 * cases like multiple whitespaces and ensures proper allocation.
 *
 * @param str The input string containing integer pairs.
 * @param double_array Pointer to the DoubleIntArray structure to populate.
 */
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