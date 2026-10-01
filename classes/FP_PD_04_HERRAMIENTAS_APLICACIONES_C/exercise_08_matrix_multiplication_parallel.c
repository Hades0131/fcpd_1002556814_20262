/**
 * @file exercise_08_matrix_multiplication_parallel.c
 * @brief Exercise 8 - Parallel matrix multiplication with OpenMP.
 *
 * @details Multiplies two NxN square matrices sequentially and in parallel using
 * #pragma omp parallel for. Shows which thread computed each row of the result
 * matrix (omp_get_thread_num()), verifies both results match and reports Ts, Tp,
 * speedup and efficiency.
 *
 
 *
 * @author Andres Benitez
 * @date 2026-09-30
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define N 600

int main(void) {
    double *A = (double *)malloc((size_t)N * N * sizeof(double));
    double *B = (double *)malloc((size_t)N * N * sizeof(double));
    double *Cseq = (double *)calloc((size_t)N * N, sizeof(double));
    double *Cpar = (double *)calloc((size_t)N * N, sizeof(double));
    int *owner = (int *)malloc(N * sizeof(int));   // thread that computed each row
    if (!A || !B || !Cseq || !Cpar || !owner) {
        printf("Error: no se pudo reservar memoria\n");
        return 1;
    }
    for (int i = 0; i < N * N; i++) {
        A[i] = (i % 7) + 1.0;
        B[i] = (i % 5) + 1.0;
    }

    // Sequential
    double t0 = omp_get_wtime();
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            double s = 0.0;
            for (int k = 0; k < N; k++) s += A[i * N + k] * B[k * N + j];
            Cseq[i * N + j] = s;
        }
    double ts = omp_get_wtime() - t0;

    // Parallel (rows distributed among threads)
    t0 = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        owner[i] = omp_get_thread_num();
        for (int j = 0; j < N; j++) {
            double s = 0.0;
            for (int k = 0; k < N; k++) s += A[i * N + k] * B[k * N + j];
            Cpar[i * N + j] = s;
        }
    }
    double tp = omp_get_wtime() - t0;

    // Verify both results match
    double maxDiff = 0.0;
    for (int i = 0; i < N * N; i++) {
        double d = fabs(Cseq[i] - Cpar[i]);
        if (d > maxDiff) maxDiff = d;
    }

    int p = omp_get_max_threads();
    int *rowsPerThread = (int *)calloc(p, sizeof(int));
    for (int i = 0; i < N; i++) rowsPerThread[owner[i]]++;

    printf("Matrices %dx%d, hilos = %d\n", N, N, p);
    printf("Diferencia maxima secuencial vs paralelo: %g\n\n", maxDiff);

    printf("Primeras 12 filas y el hilo que las calculo:\n");
    for (int i = 0; i < 12 && i < N; i++)
        printf("  Fila %3d -> hilo %d\n", i, owner[i]);

    printf("\nFilas calculadas por hilo:\n");
    for (int t = 0; t < p; t++)
        printf("  Hilo %d: %d filas\n", t, rowsPerThread[t]);

    double speedup = ts / tp;
    printf("\nTs = %.6f s\n", ts);
    printf("Tp = %.6f s\n", tp);
    printf("Speedup experimental = %.3f\n", speedup);
    printf("Eficiencia = %.3f\n", speedup / p);

    free(A); free(B); free(Cseq); free(Cpar); free(owner); free(rowsPerThread);
    return 0;
}