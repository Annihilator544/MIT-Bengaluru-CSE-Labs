#include <stdio.h>
#include <stdlib.h>

#define M 4
#define N 4
#define THREADS_PER_BLOCK 256

__global__ void computeMatrixB(int *matrixA, int *matrixB, int rows, int cols) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;

    if (row < rows && col < cols) {
        int sum = 0;
        // Compute sum of elements in ith row
        for (int j = 0; j < cols; j++) {
            sum += matrixA[row * cols + j];
        }
        // Compute sum of elements in jth column
        for (int i = 0; i < rows; i++) {
            sum += matrixA[i * cols + col];
        }
        // Store the sum in matrixB
        matrixB[row * cols + col] = sum;
    }
}

int main() {
    int matrixA[M][N] = {{1, 2, 3, 4},
                         {5, 6, 7, 8},
                         {9, 10, 11, 12},
                         {13, 14, 15, 16}};
    int matrixB[M][N];

    int *d_matrixA, *d_matrixB;
    int size = M * N * sizeof(int);

    // Allocate memory for matrix A and matrix B on device
    cudaMalloc((void **)&d_matrixA, size);
    cudaMalloc((void **)&d_matrixB, size);

    // Copy matrix A to device
    cudaMemcpy(d_matrixA, matrixA, size, cudaMemcpyHostToDevice);

    // Define grid and block dimensions
    dim3 blockSize(16, 16); // 16x16 threads per block
    dim3 gridSize((N + blockSize.x - 1) / blockSize.x, (M + blockSize.y - 1) / blockSize.y);

    // Launch kernel to compute matrix B
    computeMatrixB<<<gridSize, blockSize>>>(d_matrixA, d_matrixB, M, N);

    // Copy matrix B back to host
    cudaMemcpy(matrixB, d_matrixB, size, cudaMemcpyDeviceToHost);

    // Cleanup
    cudaFree(d_matrixA);
    cudaFree(d_matrixB);

    // Display resultant matrix B
    printf("Resultant Matrix B:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrixB[i][j]);
        }
        printf("\n");
    }

    return 0;
}
