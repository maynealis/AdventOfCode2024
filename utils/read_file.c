/**
 * @file read_file.c
 * @brief Functions to read the content of a file and store it into a string.
 * 
 * This file contains functions that handle reading content from a file.
 * It includes a `read_file` function that reads the contents of a file 
 * in chunks and dynamically allocates memory to store the content. 
 * The function `get_file_content` is the main function that opens the file
 * given the path to it and calls the `read_file` function.
 * 
 * @author Alis Mayné
 * @date 2024-12-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <unistd.h> // For read and close
#include <fcntl.h> // For open
#include <stdlib.h> // For malloc, free, realloc
#include <stdio.h> // Fot printf (to manage error)
#include "read_file.h"

#define BUFFER_SIZE 2

//TODO: separar esta funcion a un archivo de string_functions
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
 * @brief Reads the content of a file into a dynamically allocated string.
 * 
 * This function reads the file's content and puts it into a string, 
 * dynamically allocating memory to store the entire content of the file. 
 * If memory allocation fails, the function returns `NULL`.
 * 
 * @param file_id The file descriptor of the file to be read.
 * @return A pointer to a string containing the content of the file, 
 *         or `NULL` if memory allocation fails or the file is empty.
 */
char *read_file(int file_id)
{
    char *result;
    char *temp;
    char buffer[BUFFER_SIZE];
    int bytes_read;
    int total_bytes;

    bytes_read = read(file_id, buffer, sizeof(buffer));
    total_bytes = 1;
    result = malloc(1); // Start with an empty string.
    while (bytes_read > 0)
    {
        temp = realloc(result, total_bytes + bytes_read); // Resize memory to hold more data
        if (temp == NULL)
        {
            free(result);
            return NULL;
        }
        result = temp;
        string_concat(result, buffer, total_bytes - 1, bytes_read); // Append new data
        total_bytes += bytes_read;
        bytes_read = read(file_id, buffer, sizeof(buffer));
    }
    return (result);
}

/**
 * @brief Opens a file and reads its content into a string.
 * 
 * This function opens a file given its complete path and reads its content into 
 * a string by calling `read_file`.
 * If the file cannot be opened, it prints an error message and returns `NULL`.
 * If the memory allocation fails, it returns `NULL`.
 * 
 * @param file_path The complete path to the file to be read.
 * @return A pointer to the string containing the file's content, or `NULL` if 
 *         the file cannot be opened or an error occurs during reading.
 */
char *get_file_content(char *file_path)
{
    int file_id;
    char *result;
    
    file_id = open(file_path, O_RDONLY);
    if (file_id == -1)
    {
        printf("File not found.\n");
        return NULL;
    }
    result = read_file(file_id);
    close(file_id);
    return (result);
}