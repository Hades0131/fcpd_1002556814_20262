/**
 * @file cb_07_matrix and diagonals
 * @brief Create a square matrix with random numbers and compare its diagonals.
 * @author Andres Benitez
 * @date 2026-13-09
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE 50

int main() {
    int n;
    printf("Ingrese el tamano de la matriz (n x n): ");
    scanf("%d", &n);

    int matrix[n][n];
    srand(time(NULL));

    printf("Matriz generada:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % MAX_VALUE + 1;
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    int mainDiagonalSum = 0, secondaryDiagonalSum = 0;
    for (int i = 0; i < n; i++) {
        mainDiagonalSum += matrix[i][i];
        secondaryDiagonalSum += matrix[i][n - 1 - i];
    }

    printf("Suma diagonal principal: %d\n", mainDiagonalSum);
    printf("Suma diagonal secundaria: %d\n", secondaryDiagonalSum);

    if (mainDiagonalSum > secondaryDiagonalSum)
        printf("La diagonal principal es mayor.\n");
    else if (secondaryDiagonalSum > mainDiagonalSum)
        printf("La diagonal secundaria es mayor.\n");
    else
        printf("Ambas diagonales son iguales.\n");

    return 0;
}