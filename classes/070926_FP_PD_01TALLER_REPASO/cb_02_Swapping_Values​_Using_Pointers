/**
 * @file cb_02_swap values with pointers
 * @brief Swap the values of two integers using pointers.
 * @author Andres Benitez
 * @date 2026-13-09
 */

#include <stdio.h>

void swapValues(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x, y;
    printf("Ingrese dos numeros enteros: ");
    scanf("%d %d", &x, &y);

    printf("Antes: x=%d, y=%d\n", x, y);
    swapValues(&x, &y);
    printf("Despues: x=%d, y=%d\n", x, y);

    return 0;
}