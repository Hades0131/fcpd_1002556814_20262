/**
 * @file exercise_02_array_sum_pointers.c
 * @brief Exercise 2 - Sum of array elements using pointers.
 *
 * @details Traverses an integer array with a moving pointer, accumulates the sum of its
 * elements and prints the final result.
 *
 * 
 * @author Andres Benitez
 * @date 2026-09-30
 */
#include <stdio.h>

#define SIZE 10

int main(void) {
    int arr[SIZE] = {5, 12, 7, 3, 9, 21, 4, 8, 15, 6};
    int *ptr = arr;
    int *end = arr + SIZE;
    int sum = 0;

    while (ptr < end) {
        sum += *ptr;
        ptr++;
    }

    printf("La suma de los elementos es: %d\n", sum);
    return 0;
}