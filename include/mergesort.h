#ifndef MERGESORT_H
#define MERGESORT_H

#include <stdlib.h> // For malloc and NULL

int *merge(int *left, int *right, int size_left, int size_right);
int *merge_sort(int *arr, int size);

# endif /* MERGESORT_H */