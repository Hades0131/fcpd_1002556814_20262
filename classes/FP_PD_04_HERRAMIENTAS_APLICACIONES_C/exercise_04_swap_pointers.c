/**
 * @file exercise_04_swap_pointers.c
 * @brief Exercise 4 - Value swap with pointers.
 *
 * @details Implements swap(int *a, int *b), which exchanges the contents of two variables
 * through their addresses, and tests it in main().
 *
 *
 * @author Andres Benitez
 * @date 2026-09-30
 */
#include <stdio.h>

/**
 * @brief Swaps the contents of two integer variables.
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 */
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void) {
    int x = 10, y = 25;

    printf("Antes del intercambio:   x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("Despues del intercambio: x = %d, y = %d\n", x, y);
    return 0;
}