#ifndef STRING_FUNCTIONS_H
#define STRING_FUNCTIONS_H

#include <stdbool.h>

bool ft_isspace(char c);
bool ft_isdigit(char c);
void string_concat(char *str1, char *str2, int size1, int size2);
int ft_strlen(char *str);
void ft_strcpy(char *str1, char *str2);

# endif /* STRING_FUNCTIONS_H */