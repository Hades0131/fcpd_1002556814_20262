/**
 * @file cb_05_recursion with digit sum
 * @brief Recursive function that sums the digits of a number.
 * @author Andres Benitez
 * @date 2026-12-09
 */

#include <stdio.h>

int digitSum(int n) {
    if (n == 0) return 0;
    return (n % 10) + digitSum(n / 10);
}

int main() {
    int n;
    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &n);

    printf("Suma de digitos: %d\n", digitSum(n));

    return 0;
}