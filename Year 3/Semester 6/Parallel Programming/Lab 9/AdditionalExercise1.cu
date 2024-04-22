#include <stdio.h>
#include <stdlib.h>

#define M 3
#define N 3
#define THREADS_PER_BLOCK 256

__global__ void processMatrix(int *matrixA, int *matrixB, int rows, int cols) {
    int tid = blockIdx.x * blockDim.x + threadIdx.x;

    if (tid < rows * cols) {
        int row = tid / cols;
        int col = tid % cols;
        int value = matrixA[tid];

        // Calculate row sum and column sum
        int rowSum = 0;
        int colSum = 0;
        for (int i = 0; i < cols; i++) {
            rowSum += matrixA[row * cols + i];
        }
        for (int i = 0; i < rows; i++) {
            colSum += matrixA[i * cols + col];
        }

        // Replace even elements with row sum, odd elements with column sum
        matrixB[tid] = (value % 2 == 0) ? rowSum : colSum;
    }
}

int main() {
    int matrixA[M][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrixB[M][N];

    int *d_matrixA, *d_matrixB;
    int size = M * N * sizeof(int);

    // Allocate memory for matrix A and matrix B on device
    cudaMalloc((void **)&d_matrixA, size);
    cudaMalloc((void **)&d_matrixB, size);

    // Copy matrix A to device
    cudaMemcpy(d_matrixA, matrixA, size, cudaMemcpyHostToDevice);

    int numBlocks = (M * N + THREADS_PER_BLOCK - 1) / THREADS_PER_BLOCK;

    // Launch kernel to process matrix elements
    processMatrix<<<numBlocks, THREADS_PER_BLOCK>>>(d_matrixA, d_matrixB, M, N);

    // Copy matrix B back to host
    cudaMemcpy(matrixB, d_matrixB, size, cudaMemcpyDeviceToHost);

    // Cleanup
    cudaFree(d_matrixA);
    cudaFree(d_matrixB);

    // Display resultant matrix B
    printf("Matrix B:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrixB[i][j]);
        }
        printf("\n");
    }

    return 0;
}
