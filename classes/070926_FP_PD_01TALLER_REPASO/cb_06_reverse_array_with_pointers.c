/**
 * @file cb_06_reverse array with pointers
 * @brief Reverse the elements of an array using pointer arithmetic.
 * @author Andres Benitez
 * @date 2026-13-09
 */

#include <stdio.h>

void reverseArray(int *arr, int size) {
    int *start = arr;
    int *end = arr + (size - 1);
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    int n;
    printf("Ingrese el tamano del arreglo: ");
    scanf("%d", &n);

    int array[n];
    printf("Ingrese %d numeros: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &array[i]);

    reverseArray(array, n);

    printf("Arreglo invertido: ");
    for (int i = 0; i < n; i++) printf("%d ", array[i]);
    printf("\n");

    return 0;
}