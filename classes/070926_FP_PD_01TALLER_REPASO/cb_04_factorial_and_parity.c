/**
 * @file cb_04_factorial and parity
 * @brief Calculate the factorial of a number and check if it is even or odd.
 * @author Andres Benitez
 * @date 2026-13-09
 */

#include <stdio.h>

long factorialFor(int n) {
    long result = 1;
    for (int i = 2; i <= n; i++) result *= i;
    return result;
}

long factorialWhile(int n) {
    long result = 1;
    int i = 2;
    while (i <= n) {
        result *= i;
        i++;
    }
    return result;
}

int main() {
    int n;
    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &n);

    printf("Factorial (for): %ld\n", factorialFor(n));
    printf("Factorial (while): %ld\n", factorialWhile(n));

    if (n % 2 == 0) printf("%d es par\n", n);
    else printf("%d es impar\n", n);

    return 0;
}