#include "read_file.h"
#include "config.h"

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
#include "string_functions.h"

#define BUFFER_SIZE 512

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
 * This function opens a file given its name and reads its content into 
 * a string by calling `read_file`.
 * If the file cannot be opened, it prints an error message and returns `NULL`.
 * If the memory allocation fails, it returns `NULL`.
 * 
 * @param file_name The name of the file to be read (e.g. "day01.txt").
 * @return A pointer to the string containing the file's content, or `NULL` if 
 *         the file cannot be opened or an error occurs during reading.
 */
char *get_file_content(char *file_name)
{
    int file_id;
    char *result;
    char *file_path;
    
    file_path = malloc((ft_strlen(file_name) + ft_strlen(INPUT_DIR)) * sizeof(char));
    if (file_path == NULL)
        return NULL;
    ft_strcpy(file_path, INPUT_DIR);
    string_concat(file_path, file_name, ft_strlen(file_path), ft_strlen(file_name));
    file_id = open(file_path, O_RDONLY);
    if (file_id == -1)
    {
        printf("File not found.\n");
        free(file_path);
        return NULL;
    }
    result = read_file(file_id);
    close(file_id);
    free(file_path);
    return (result);
}