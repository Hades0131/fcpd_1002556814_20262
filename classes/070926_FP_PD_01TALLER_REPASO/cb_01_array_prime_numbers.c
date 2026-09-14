/**
 * @file cb_01_prime numbers in an array
 * @brief Generate an array of random numbers and count how many are prime.
 * @author Andres Benitez
 * @date 2026-07-09
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define MAX_VALOR 100 

int esPrimo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}
 
int main() {
    int n;
    printf("Ingrese el tamano del arreglo: ");
    scanf("%d", &n);
 
    int arreglo[n];
    srand(time(NULL));
 
    int contadorPrimos = 0;
    for (int i = 0; i < n; i++) {
        arreglo[i] = rand() % MAX_VALOR + 1;
        if (esPrimo(arreglo[i])) contadorPrimos++;
    }
 
    printf("Arreglo generado: ");
    for (int i = 0; i < n; i++) printf("%d ", arreglo[i]);
    printf("\nCantidad de numeros primos: %d\n", contadorPrimos);
 
    return 0;
}