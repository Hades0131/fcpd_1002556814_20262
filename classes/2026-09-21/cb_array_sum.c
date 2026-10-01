/**
 * @file cb_01_prime numbers in an array
 * @brief array sum paralelo
 * @author Andres Benitez
 * @date 2026-21-09
 */


#include <stdio.h>
#include <stdlib.h>

# define N 200000000

long long sumArray(int *array, int size) {
    long long sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}


void fillArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        *(array + i) = i % 100 + 1; 
    }
}

void print_array(int *array, int size){

    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i ==( size - 1)) {
            printf("%d]\n", *(array + i));
            break;
        }
        printf("%d,", *(array + i));
    }
}
    


int main(){
    int size= N;
    int *arr= malloc( size * sizeof(int));
    if ( arr == NULL){
        printf("no hay suficiente memoria para  N = %d\n", N);
        return 1;
    }
    fillArray(arr, size);
    print_array(arr, size);

    free(arr);
    return 0;
}