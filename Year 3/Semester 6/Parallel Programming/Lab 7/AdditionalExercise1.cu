#include <stdio.h>

__global__ void vectorAdd(float *x, float *y, float alpha, int n) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx < n) {
        y[idx] = alpha * x[idx] + y[idx];
    }
}

int main() {
    int n = 10; // size of vectors
    float alpha = 2.0f; // scalar value
    int size = n * sizeof(float);
    float *h_x, *h_y; // host arrays
    float *d_x, *d_y; // device arrays

    // Allocate memory on the host
    h_x = (float*)malloc(size);
    h_y = (float*)malloc(size);

    // Initialize input vectors x and y
    for (int i = 0; i < n; i++) {
        h_x[i] = i; // some example data
        h_y[i] = i * 2; // some example data
    }

    // Allocate memory on the device
    cudaMalloc((void**)&d_x, size);
    cudaMalloc((void**)&d_y, size);

    // Copy data from host to device
    cudaMemcpy(d_x, h_x, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_y, h_y, size, cudaMemcpyHostToDevice);

    // Define grid and block dimensions
    int blockSize = 256;
    int numBlocks = (n + blockSize - 1) / blockSize;

    // Launch the CUDA kernel
    vectorAdd<<<numBlocks, blockSize>>>(d_x, d_y, alpha, n);

    // Copy result back to host
    cudaMemcpy(h_y, d_y, size, cudaMemcpyDeviceToHost);

    // Print the result array (for verification)
    printf("Result of y = αx + y:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", h_y[i]);
    }
    printf("\n");

    // Free device memory
    cudaFree(d_x);
    cudaFree(d_y);

    // Free host memory
    free(h_x);
    free(h_y);

    return 0;
}
