#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "read_file.h"

#define BUFFER_SIZE 2

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

char *read_file(int file_id)
{
    char *result;
    char *temp;
    char buffer[BUFFER_SIZE];
    int bytes_read;
    int total_bytes;

    bytes_read = read(file_id, buffer, sizeof(buffer));
    total_bytes = 1;
    result = malloc(1);
    while (bytes_read > 0)
    {
        temp = realloc(result, total_bytes + bytes_read);
        if (temp == NULL)
        {
            free(result);
            return NULL;
        }
        result = temp;
        string_concat(result, buffer, total_bytes - 1, bytes_read);
        total_bytes += bytes_read;
        bytes_read = read(file_id, buffer, sizeof(buffer));
    }
    return (result);
}

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
    return result;
}