#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 4
#define THREADS_PER_BLOCK 256

// CUDA kernel to calculate factorial
__device__ int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// CUDA kernel to calculate sum of digits
__device__ int sumOfDigits(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

__global__ void processMatrix(int *matrix) {
    int tid = blockIdx.x * blockDim.x + threadIdx.x;

    if (tid < N * N) {
        int row = tid / N;
        int col = tid % N;
        int value = matrix[tid];

        if (row == col) {
            matrix[tid] = 0; // Replace principal diagonal elements with zero
        } else if (row < col) {
            // Calculate factorial for elements above the principal diagonal
            matrix[tid] = factorial(value);
        } else {
            // Calculate sum of digits for elements below the principal diagonal
            matrix[tid] = sumOfDigits(value);
        }
    }
}

int main() {
    int matrix[N][N] = {{1, 2, 3, 4},
                        {5, 6, 7, 8},
                        {9, 10, 11, 12},
                        {13, 14, 15, 16}};

    int *d_matrix;
    int size = N * N * sizeof(int);

    // Allocate memory for matrix A on device
    cudaMalloc((void **)&d_matrix, size);

    // Copy matrix A to device
    cudaMemcpy(d_matrix, matrix, size, cudaMemcpyHostToDevice);

    int numBlocks = (N * N + THREADS_PER_BLOCK - 1) / THREADS_PER_BLOCK;

    // Launch kernel to process matrix elements
    processMatrix<<<numBlocks, THREADS_PER_BLOCK>>>(d_matrix);

    // Copy matrix back to host
    cudaMemcpy(matrix, d_matrix, size, cudaMemcpyDeviceToHost);

    // Cleanup
    cudaFree(d_matrix);

    // Display resultant matrix
    printf("Resultant Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
