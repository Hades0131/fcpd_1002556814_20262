/**
 * @file cb_09_dynamic memory with arrays
 * @brief Create a dynamic array, fill it with user values and calculate its sum.
 * @author Andres Benitez
 * @date 2026-13-09
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Ingrese el numero de elementos: ");
    scanf("%d", &n);

    int *array = (int *) malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }

    printf("Ingrese %d valores: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &array[i]);

    int sum = 0;
    for (int i = 0; i < n; i++) sum += array[i];

    printf("Suma total: %d\n", sum);

    free(array);
    return 0;
}