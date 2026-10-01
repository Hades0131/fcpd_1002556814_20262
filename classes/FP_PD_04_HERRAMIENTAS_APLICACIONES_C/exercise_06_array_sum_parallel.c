/**
 * @file exercise_06_array_sum_parallel.c
 * @brief Exercise 6 - Parallel array sum with OpenMP.
 *
 * @details Computes the sum of an array of N = 1,000,000 elements sequentially and in
 * parallel (#pragma omp parallel for reduction(+:sumPar)). Execution times are
 * measured with omp_get_wtime() to obtain Ts, Tp, speedup and efficiency.
 *

 *
 * @author Andres Benitez
 * @date 2026-09-30
 */
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000

int main(void) {
    int *arr = (int *)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Error: no se pudo reservar memoria\n");
        return 1;
    }
    for (int i = 0; i < N; i++) arr[i] = (i % 10) + 1;

    // Sequential
    double t0 = omp_get_wtime();
    long long sumSeq = 0;
    for (int i = 0; i < N; i++) sumSeq += arr[i];
    double ts = omp_get_wtime() - t0;

    // Parallel
    t0 = omp_get_wtime();
    long long sumPar = 0;
    #pragma omp parallel for reduction(+:sumPar)
    for (int i = 0; i < N; i++) sumPar += arr[i];
    double tp = omp_get_wtime() - t0;

    int p = omp_get_max_threads();
    double speedup = ts / tp;
    double efficiency = speedup / p;

    printf("N = %d, hilos = %d\n", N, p);
    printf("Suma secuencial: %lld\n", sumSeq);
    printf("Suma paralela:   %lld\n", sumPar);
    printf("Ts = %.6f s\n", ts);
    printf("Tp = %.6f s\n", tp);
    printf("Speedup experimental = %.3f\n", speedup);
    printf("Eficiencia = %.3f\n", efficiency);

    free(arr);
    return 0;
}