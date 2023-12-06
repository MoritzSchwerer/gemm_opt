#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N 1024

float A[N*N] __attribute__ ((aligned (64)));
float B[N*N] __attribute__ ((aligned (64)));
float C[N*N] __attribute__ ((aligned (64)));
float TEMP[N*N] __attribute__ ((aligned (64)));

void swapped_loop_mul() {
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            for (int j = 0; j < N; j++) {
                C[(i*N) + j] += A[(i*N) + k] * B[(k*N) + j];
            }
        }
    }
}

void init_matrix() {
    for (int i = 0; i < N*N; i++) {
        A[i] = (float)(rand() % 1000000) / 1000000.0f;
        B[i] = (float)(rand() % 1000000) / 1000000.0f;
        C[i] = 0.0f;
        TEMP[i] = 0.0f;
    }
}

int main() {
    init_matrix();

    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);
    swapped_loop_mul();
    gettimeofday(&end_time, NULL);
    double elapsed_time = (end_time.tv_sec - start_time.tv_sec) +
                          (end_time.tv_usec - start_time.tv_usec) / 1e6;
    printf("Elapsed time: %f seconds\n", elapsed_time);

    return 0;
}


