#include <stdbool.h>
#include <stdio.h> // printf
#include <stdlib.h> //malloc
#include "read_file.h"
#include "string_functions.h"


void reset_arr(int *arr, int size)
{
    for (int aux = 0; aux < size; aux++)
    {
        arr[aux] = 0;
    }
}

bool is_line_safe(int *arr, int size)
{
    int i;
    int current_diff;
    int previous_diff;
    bool is_safe;

    i = 0;
    previous_diff = 0;
    is_safe = true;
    while (i < (size - 1) && is_safe)
    {
        current_diff = arr[i + 1] - arr[i];
        if ((current_diff < 0 && previous_diff <= 0) || (current_diff > 0 && previous_diff >= 0))
        {
            if (current_diff >= -3 && current_diff <= 3 && current_diff != 0)
            {
                i++;
                previous_diff = current_diff;
            }
            else
            {
                i = 0;
                previous_diff = 0;
                is_safe = false;
            }
        }
        else
        {
            i = 0;
            previous_diff = 0;
            is_safe = false;
        }
    }
    return (is_safe);
}

int main(void)
{
    char *str;
    int i;
    int n;
    int result;
    int arr[16]; //16 es un numero que definirem per M<ACRO que sigui mes gramn del que necessitem.

    //Inicialize the array with 0
    reset_arr(arr, 16);

    str = get_file_content("test02.txt");

    i = 0;
    n = 0;
    result = 0;
    while (str[i] != '\0')
    {
        if (ft_isdigit(str[i]))
        {
            arr[n] = arr[n] * 10 + (str[i] - '0');
        }
        else if (ft_isspace(str[i]) && !ft_isspace(str[i - 1]))
            n++;
        else if (str[i] == '\n')
        {
            if (is_line_safe(arr, n + 1, true))
                result++;
            reset_arr(arr, 16);
            n = 0;
        }
        i++;
    }
    // Check the last line (ended in \0, not \n)
    if (is_line_safe(arr, n + 1, true))
        result++;
    printf("El numero de safe es: %d", result);
    return (1);
}