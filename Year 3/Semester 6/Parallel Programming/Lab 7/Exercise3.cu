#include <stdio.h>

#define MASK_WIDTH 3
#define TILE_WIDTH 32

__global__ void convolutionKernel(float *N, float *M, float *P, int width) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    int radius = MASK_WIDTH / 2;
    float result = 0.0f;

    for (int i = -radius; i <= radius; i++) {
        int index = idx + i;
        if (index >= 0 && index < width) {
            result += N[index] * M[i + radius];
        }
    }

    P[idx] = result;
}

int main() {
    int width = 10; // size of input array
    int mask_width = MASK_WIDTH;
    int size = width * sizeof(float);
    float *h_N, *h_M, *h_P; // host arrays
    float *d_N, *d_M, *d_P; // device arrays

    // Allocate memory on the host
    h_N = (float*)malloc(size);
    h_M = (float*)malloc(mask_width * sizeof(float));
    h_P = (float*)malloc(size);

    // Initialize input array and mask array
    for (int i = 0; i < width; i++) {
        h_N[i] = i; // some example data
    }
    for (int i = 0; i < mask_width; i++) {
        h_M[i] = 1.0f; // simple mask for averaging
    }

    // Allocate memory on the device
    cudaMalloc((void**)&d_N, size);
    cudaMalloc((void**)&d_M, mask_width * sizeof(float));
    cudaMalloc((void**)&d_P, size);

    // Copy data from host to device
    cudaMemcpy(d_N, h_N, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_M, h_M, mask_width * sizeof(float), cudaMemcpyHostToDevice);

    // Define grid and block dimensions
    dim3 dimGrid((width + TILE_WIDTH - 1) / TILE_WIDTH, 1, 1);
    dim3 dimBlock(TILE_WIDTH, 1, 1);

    // Launch the CUDA kernel
    convolutionKernel<<<dimGrid, dimBlock>>>(d_N, d_M, d_P, width);

    // Copy result back to host
    cudaMemcpy(h_P, d_P, size, cudaMemcpyDeviceToHost);

    // Print the result array
    printf("Result of convolution:\n");
    for (int i = 0; i < width; i++) {
        printf("%.2f ", h_P[i]);
    }
    printf("\n");

    // Free device memory
    cudaFree(d_N);
    cudaFree(d_M);
    cudaFree(d_P);

    // Free host memory
    free(h_N);
    free(h_M);
    free(h_P);

    return 0;
}
