#ifndef ADVENT_FILE_PARSER_H
#define ADVENT_FILE_PARSER_H

#include <stdbool.h> //For bool

//TODO:necesito la aclaracion de cada cosa dentro del struct?
/**
 * @struct DoubleIntArray
 * @brief A structure to store two dynamically allocated arrays of unsigned integers.
 *
 * This structure is designed to hold two arrays of unsigned integers, along with
 * their respective sizes. It is particularly useful for cases where pairs of integers
 * need to be managed separately but in a synchronized manner.
 * 
 */
typedef struct DoubleIntArray
{
    unsigned int *first;        /**< Pointer to the first array of unsigned integers. */
    unsigned int *second;       /**< Pointer to the second array of unsigned integers. */
    unsigned int size_first;    /**< The size of the first array. */
    unsigned int size_second;   /**< The size of the second array. */
} DoubleIntArray;

bool ft_isspace(char c);
DoubleIntArray *create_double_int_array();
void parse_adv1(char *str, DoubleIntArray* double_array);

#endif /* ADVENT_FILE_PARSER_H */