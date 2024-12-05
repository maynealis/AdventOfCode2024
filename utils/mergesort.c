#include <stdlib.h>
#include <stdio.h>
# include "mergesort.h"

int *merge_sort(int *arr, int size)
{
    int left_size;
    int right_size;
    int *left_half;
    int *right_half;

    if (size <= 1)
        return arr;
    left_size = size / 2;
    right_size = size - left_size;
    left_half = arr;
    right_half = &arr[left_size];
    return merge(merge_sort(left_half, left_size), merge_sort(right_half, right_size), left_size, right_size);
}

int *merge(int *left, int *right, int size_left, int size_right)
{
    int *result = malloc((size_left + size_right) * sizeof(int));
    if (result == NULL)
        return (NULL);
    int i = 0;
    int j = 0;

    if (left[size_left - 1] <= right[0])
    {
        while (i < size_left)
        {
            result[i] = left[i];
            i++;
        }
        while (j < size_right)
        {
            result[i + j] = right[j];
            j++;
        }
    }
    else if (right[size_right - 1] <= left[0])
    {
        while (j < size_right)
        {
            result[j] = right[j];
            j++;
        }
        while (i < size_left)
        {
            result[i + j] = left[i];
            i++;
        }
    }
    else
    {
        while (i < size_left && j < size_right)
        {
            if (left[i] < right[j])
            {
                result[i + j] = left[i];
                i++;
            }
            else
            {
                result[i + j] = right[j];
                j++;
            }
        }
        while (i < size_left)
        {
            result[i + j] = left[i];
            i++;
        }
        while (j < size_right)
        {
            result[i + j] = right[j];
            j++;
        }
    }
    return (result);
}

// int main(void)
// {
//     int a[] = {45, 3, -7, 2, 8};
//     int *b = merge_sort(a, 5);
//     printf("%d\n", b[0]);
//     printf("%d\n", b[1]);
//     printf("%d\n", b[2]);
//     printf("%d\n", b[3]);
//     printf("%d\n", b[4]);
//     printf("%d\n", b[5]);
//     return (0);
// }