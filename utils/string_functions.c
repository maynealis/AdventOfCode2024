#include "string_functions.h"

/**
 * @brief Checks if a character is a whitespace character.
 *
 * This function determines whether a given character is one of the 
 * whitespace characters: space, tab, vertical tab, carriage return, 
 * or form feed.
 *
 * @param c The character to check.
 * @return true if the character is a whitespace, false otherwise.
 */
bool ft_isspace(char c)
{
    if (c == ' ' || c == '\t' || c == '\v' || c == '\r' || c == '\f')
        return true;
    return false;
}

/**
 * @brief Checks if a character is a digit.
 * 
 * @param c The character to check.
 * @return true if the character is a digit, false otherwise.
 */
bool ft_isdigit(char c)
{
    if (c >= '0' && c<= '9')
        return true;
    return false;
}

//TODO: fer que retorni el primer str
/**
 * @brief Concatenates two strings into the first string.
 *
 * This function appends `str2` to the end of `str1`. It assumes that `str1` 
 * has enough space allocated to hold the result. The function modifies `str1`
 * in-place by adding characters from `str2` starting at the position after
 * the current size of `str1`.
 *
 * @param str1 The first string to which `str2` will be appended.
 * @param str2 The second string to be concatenated to `str1`.
 * @param size1 The current length of `str1`.
 * @param size2 The length of `str2`.
 */
void string_concat(char *str1, char *str2, int size1, int size2)
{
    int i;

    i = 0;
    while(i < size2)
    {
        str1[size1 + i] = str2[i];
        i++;
    }
    str1[size1 + i] = '\0';
}

/**
 * @brief Returns the size of the string. The string must be null-terminated.
 * 
 * @param str The string to calculate the size.
 * @return The size of the string.
 */
int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

/**
 * @brief Copies the content of the second string to the first string. 
 * 
 * It assumes that there is enough space in the first string.
 * 
 * @param str1 The destination copied string.
 * @param str2 The source string to copy from.
 */
void ft_strcpy(char *str1, char *str2)
{
    int i;

    i = 0;
    while (str2[i] != '\0')
    {
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';
}