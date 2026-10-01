/**
 * @file exercise_07_dot_product_parallel.c
 * @brief Exercise 7 - Dot product of two vectors with OpenMP.
 *
 * @details Computes the dot product of two vectors of size N sequentially and in parallel
 * using reduction. omp_get_thread_num() and omp_get_num_threads() are used to
 * show which threads take part in the computation. Reports Ts, Tp, speedup and
 * efficiency.
 *
 *
 * @author Andres Benitez
 * @date 2026-09-30
 */
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 10000000

int main(void) {
    double *a = (double *)malloc(N * sizeof(double));
    double *b = (double *)malloc(N * sizeof(double));
    if (a == NULL || b == NULL) {
        printf("Error: no se pudo reservar memoria\n");
        return 1;
    }
    for (int i = 0; i < N; i++) {
        a[i] = 1.0;
        b[i] = (i % 5) + 1.0;
    }

    // Sequential
    double t0 = omp_get_wtime();
    double dotSeq = 0.0;
    for (int i = 0; i < N; i++) dotSeq += a[i] * b[i];
    double ts = omp_get_wtime() - t0;

    // Parallel
    t0 = omp_get_wtime();
    double dotPar = 0.0;
    #pragma omp parallel reduction(+:dotPar)
    {
        #pragma omp critical
        printf("Hilo %d de %d participa en el calculo\n",
               omp_get_thread_num(), omp_get_num_threads());

        #pragma omp for
        for (int i = 0; i < N; i++) dotPar += a[i] * b[i];
    }
    double tp = omp_get_wtime() - t0;

    int p = omp_get_max_threads();
    double speedup = ts / tp;

    printf("\nN = %d, hilos = %d\n", N, p);
    printf("Producto escalar secuencial: %.1f\n", dotSeq);
    printf("Producto escalar paralelo:   %.1f\n", dotPar);
    printf("Ts = %.6f s\n", ts);
    printf("Tp = %.6f s\n", tp);
    printf("Speedup experimental = %.3f\n", speedup);
    printf("Eficiencia = %.3f\n", speedup / p);

    free(a);
    free(b);
    return 0;
}