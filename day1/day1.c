#include "../utils/advent_file_parser.h"
#include "../utils/read_file.h"
#include "../utils/mergesort.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *first_sorted;
    int *second_sorted;
    int i;
    int result;

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
    i = 0;
    result = 0;
    while (i < double_array->size_first)
    {
        if (first_sorted[i] <= second_sorted[i])
            result += second_sorted[i] - first_sorted[i];
        else
            result += first_sorted[i] - second_sorted[i];
        i++;
    }
    printf("El resultado es: %d", result);
    return (0);
}