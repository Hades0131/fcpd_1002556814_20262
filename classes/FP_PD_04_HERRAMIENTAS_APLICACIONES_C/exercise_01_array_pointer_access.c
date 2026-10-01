/**
 * @file exercise_01_array_pointer_access.c
 * @brief Exercise 1 - Array element access with pointers.
 *
 * @details Declares an array of 10 integers, initializes it with the values 1 to 10 and prints
 * each element using pointer arithmetic (*(ptr + i)).
 *
 *
 *
 * @author Andres Benitez
 * @date 2026-09-30
 */
#include <stdio.h>

#define SIZE 10

int main(void) {
    int arr[SIZE];
    int *ptr = arr;

    for (int i = 0; i < SIZE; i++) {
        *(ptr + i) = i + 1;              
    }

    printf("Elementos del arreglo (aritmetica de punteros):\n");
    for (int i = 0; i < SIZE; i++) {
        printf("*(ptr+%d) = %d\n", i, *(ptr + i));
    }
    return 0;
}