/**
 * @file cb_03_max and min with ternary operators
 * @brief Determine the maximum and minimum of three numbers.
 * @author Andres Benitez
 * @date 2026-13-09
 */

#include <stdio.h>

int getMax(int a, int b, int c) {
    int m = (a > b) ? a : b;
    return (m > c) ? m : c;
}

int getMin(int a, int b, int c) {
    int m = (a < b) ? a : b;
    return (m < c) ? m : c;
}

int main() {
    int a, b, c;
    printf("Ingrese tres numeros enteros: ");
    scanf("%d %d %d", &a, &b, &c);

    printf("Mayor: %d\n", getMax(a, b, c));
    printf("Menor: %d\n", getMin(a, b, c));

    return 0;
}