#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void prim_mul(float** result, float** x, float** y, int num_elems) {
    for (int i = 0; i < num_elems; i++) {
        for (int j = 0; j < num_elems; j++) {
            for (int k = 0; k < num_elems; k++) {
                result[i][j] += x[i][k] * y[k][j];
            }
        }
    }
}

void swap_loops_mul(float** result, float** x, float** y, int num_elems) {
    for (int i = 0; i < num_elems; i++) {
        for (int k = 0; k < num_elems; k++) {
            for (int j = 0; j < num_elems; j++) {
                result[i][j] += x[i][k] * y[k][j];
            }
        }
    }
}


float** init_matrix(int n, int zero_init) {
    float** matrix = (float**)malloc(n * sizeof(float*));

    for (int i = 0; i < n; i++) {
        matrix[i] = (float*)malloc(n * sizeof(float));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (zero_init) {
                matrix[i][j] = 0.0f;
            } else {
                matrix[i][j] = (float)(rand() % 1000000) / 1000000.0f;

            }
        }
    }
    return matrix;
}

int main() {
    int n = 1024;
    float** x = init_matrix(n, 0);
    float** y = init_matrix(n, 0);
    float** res = init_matrix(n, 1);

    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    swap_loops_mul(res, x, y, n);

    gettimeofday(&end_time, NULL);
    double elapsed_time = (end_time.tv_sec - start_time.tv_sec) +
                          (end_time.tv_usec - start_time.tv_usec) / 1e6;

    printf("Elapsed time: %f seconds\n", elapsed_time);

    return 0;
}


