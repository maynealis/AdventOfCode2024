#include "../utils/advent_file_parser.h"
#include "../utils/read_file.h"
#include "../utils/mergesort.h"
#include <stdio.h>
#include <stdlib.h>

int solve_part1(int *first_sorted, int *second_sorted, int size)
{
    int i;
    int result;

    i = 0;
    result = 0;
    while (i < size)
    {
        if (first_sorted[i] <= second_sorted[i])
            result += second_sorted[i] - first_sorted[i];
        else
            result += first_sorted[i] - second_sorted[i];
        i++;
    }
    return (result);
}

int count_number(int num, int *arr, int size)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (i < size && arr[i] <= num)
    {
        if (num == arr[i])
            count++;
        i++;
    }
    return (count);
}

int solve_part2(int *first_sorted, int *second_sorted, int size)
{
    int i;
    int result;

    i = 0;
    result = 0;
    while (i < size)
    {
        result += first_sorted[i] * count_number(first_sorted[i], second_sorted, size);   
        i++;
    }
    return (result);
}

int main(void)
{
    int *first_sorted;
    int *second_sorted;
    int distance;
    int similarity;

    char *str = get_file_content("/Users/mayne/Documents/1-PROJECTS/Programacio/AdventOfCode2024/day1/input.txt");
    DoubleIntArray *double_array = create_double_int_array();
    parse_adv1(str, double_array);
    first_sorted = malloc(double_array->size_first * sizeof(int));
    if (first_sorted == NULL)
        return (1);
    second_sorted = malloc(double_array->size_second * sizeof(int));
    if (second_sorted == NULL)
    {
        free(first_sorted); //TODO: gestionar el free de los arrays originales tamb!
        return (1);
    }
    first_sorted = merge_sort((int*)double_array->first, double_array->size_first);
    second_sorted = merge_sort((int*)double_array->second, double_array->size_second);
    distance = solve_part1(first_sorted, second_sorted, double_array->size_first);
    printf("El resultado de la primera parte es: %d\n", distance);
    similarity = solve_part2(first_sorted, second_sorted, double_array->size_first);
    printf("El resultado de la segunda parte es: %d\n", similarity);
    return (0);
}