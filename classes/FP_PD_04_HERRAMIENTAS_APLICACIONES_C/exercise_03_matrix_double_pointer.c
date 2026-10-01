/**
 * @file exercise_03_matrix_double_pointer.c
 * @brief Exercise 3 - Matrices and pointers to pointers.
 *
 * @details Builds a 3x3 integer matrix using int **matrix with dynamic memory allocation,
 * initializes it and prints it using pointer arithmetic (*(*(matrix + i) + j)).
 * All allocated memory is released before exiting.
 *
 * 
 *
 * @author Andres Benitez
 * @date 2026-09-30
 */
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

int main(void) {
    int **matrix = (int **)malloc(ROWS * sizeof(int *));
    if (matrix == NULL) {
        printf("Error: no se pudo reservar memoria\n");
        return 1;
    }

    for (int i = 0; i < ROWS; i++) {
        *(matrix + i) = (int *)malloc(COLS * sizeof(int));
        if (*(matrix + i) == NULL) {
            printf("Error: no se pudo reservar memoria\n");
            return 1;
        }
        for (int j = 0; j < COLS; j++) {
            *(*(matrix + i) + j) = i * COLS + j + 1;   
        }
    }

    printf("Contenido de la matriz 3x3:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%4d", *(*(matrix + i) + j));
        }
        printf("\n");
    }

    for (int i = 0; i < ROWS; i++) {
        free(*(matrix + i));
    }
    free(matrix);
    return 0;
}