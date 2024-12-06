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

int *remove_index(int *arr, int size, int index)
{
    int i;
    int *new_arr;

    new_arr = malloc((size - 1) * sizeof(int));
    i = 0;
    while (i < index)
    {
        new_arr[i] = arr[i];
        i++;
    }
    i = index;
    while (i < (size - 1))
    {
        new_arr[i] = arr[i + 1];
        i++;
    }
    return (new_arr);
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

bool check_conditions(int current_diff, int previous_diff)
{
    if ((current_diff < 0 && previous_diff <= 0) || (current_diff > 0 && previous_diff >= 0))
    {
        if (current_diff >= -3 && current_diff <= 3 && current_diff != 0)
            return (true);
        else
            return (false);
    }
    return (false);
}

bool is_line_safe2(int *arr, int size, bool allow_tolerance)
{
    int i;
    int current_diff;
    int previous_diff;
    bool is_safe;
    // int *arr_opt1;
    // int *arr_opt2;

    i = 0;
    previous_diff = 0;
    is_safe = true;
    while (i < (size - 1) && is_safe)
    {
        current_diff = arr[i + 1] - arr[i];
        if (check_conditions(current_diff, previous_diff))
        {
            i++;
            previous_diff = current_diff;
        }
        else if (allow_tolerance)
        {
            int aux = 0;
            while (aux <= i + 1)
            {
                if (is_line_safe2(remove_index(arr, size, aux), size - 1, false))
                {
                    return true;
                }
                else
                {
                    aux++;
                }
            }
            is_safe = false;
            // arr_opt1 = remove_index(arr, size, i);
            // if (!is_line_safe2(arr_opt1, size - 1, false))
            // {
            //     free(arr_opt1);
            //     arr_opt2 = remove_index(arr, size, i + 1);
            //     if (!is_line_safe2(arr_opt2, size - 1, false))
            //         is_safe = false;
            //     free(arr_opt2);
            //     break ;
            // }
            // else
            // {
            //     free(arr_opt1);
            //     break ;
            // }
        }
        else
            is_safe = false;
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

    str = get_file_content("day02.txt");

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
            if (is_line_safe2(arr, n + 1, true))
                result++;
            reset_arr(arr, 16);
            n = 0;
        }
        i++;
    }
    // Check the last line (ended in \0, not \n)
    if (is_line_safe2(arr, n + 1, true))
        result++;
    printf("El numero de safe es: %d", result);
    return (1);
}