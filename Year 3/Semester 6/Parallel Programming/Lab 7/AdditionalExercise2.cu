#include <stdio.h>

#define N_ROWS 4
#define N_COLS 5

__global__ void selectionSortRows(float *matrix, int numCols) {
    int rowIdx = blockIdx.x;
    int startIdx = rowIdx * numCols;

    for (int i = 0; i < numCols - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < numCols; j++) {
            if (matrix[startIdx + j] < matrix[startIdx + minIdx]) {
                minIdx = j;
            }
        }
        // Swap elements
        float temp = matrix[startIdx + i];
        matrix[startIdx + i] = matrix[startIdx + minIdx];
        matrix[startIdx + minIdx] = temp;
    }
}

int main() {
    float h_matrix[N_ROWS][N_COLS] = {
        {5, 3, 1, 4, 2},
        {9, 6, 8, 7, 10},
        {15, 13, 11, 14, 12},
        {19, 16, 18, 17, 20}
    };

    int size = N_ROWS * N_COLS * sizeof(float);
    float *d_matrix;

    // Allocate memory on the device
    cudaMalloc((void**)&d_matrix, size);

    // Copy data from host to device
    cudaMemcpy(d_matrix, h_matrix, size, cudaMemcpyHostToDevice);

    // Define grid and block dimensions
    dim3 gridDim(N_ROWS, 1, 1);

    // Launch the CUDA kernel to sort each row
    selectionSortRows<<<gridDim, 1>>>(d_matrix, N_COLS);

    // Copy the sorted data back to host
    cudaMemcpy(h_matrix, d_matrix, size, cudaMemcpyDeviceToHost);

    // Print the sorted matrix (for verification)
    printf("Sorted Matrix:\n");
    for (int i = 0; i < N_ROWS; i++) {
        for (int j = 0; j < N_COLS; j++) {
            printf("%.2f ", h_matrix[i][j]);
        }
        printf("\n");
    }

    // Free device memory
    cudaFree(d_matrix);

    return 0;
}
