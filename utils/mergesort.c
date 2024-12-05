/**
 * @file mergesort.c
 * @brief Implementation of the MergeSort algorithm.
 *
 * This file contains the functions required to perform the Merge Sort algorithm. 
 * It divides an array into halves, sorts them recursively, and finally merges 
 * them into a single sorted array.
 * 
 * @author Alis Mayné
 * @date 2024-12-05
 */

#include <stdlib.h> // For malloc and NULL
#include "mergesort.h"

/**
 * @brief Sorts an array of integers using the Merge Sort algorithm.
 * 
 * This function recursively divides the array into two halves until 
 * each subarray contains a single element or is empty.
 * Then, it merges the sorted subarrays using the `merge` function to 
 * produce a fully sorted array.
 * 
 * @param arr The array of integes to sort.
 * @param size The size of the array.
 * @return A new sorted array of int. 
 *         If the size is less than or equal to 1,returns the original array.
 *         Returns NULL if memory allocation fails.
 */
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

/**
 * @brief Merges two sorted arrays into a single sorted array.
 *
 * This function takes two sorted arrays and combines them into a third
 * array that is also sorted. It optimizes the process by checking if
 * one of the arrays can be directly concatenated to the other without
 * performing element comparisons.
 * 
 * @param left The first sorted array.
 * @param right The second sorted array.
 * @param size_left The size of the first sorted array.
 * @param size_right The size of the second sorted array.
 * @return A new sorted array that combines `left` and `right`.
 *         Returns NULL if memory allocation fails.
 */
int *merge(int *left, int *right, int size_left, int size_right)
{
    int *result = malloc((size_left + size_right) * sizeof(int));
    if (result == NULL)
        return (NULL);
    int i = 0;
    int j = 0;

    // Optimized case: the entire left array is less than or equal to the right array.
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
    // Optimized case: the entire right array is less than or equal to the left array.
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
    // General case: merge the two arrays comparing each element in order.
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
        // Add values from the rest of the left array (if any).
        while (i < size_left)
        {
            result[i + j] = left[i];
            i++;
        }
        // Add values from the rest of the right array (if any).
        while (j < size_right)
        {
            result[i + j] = right[j];
            j++;
        }
    }
    return (result);
}