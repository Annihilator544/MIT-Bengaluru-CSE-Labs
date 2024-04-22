#include <stdio.h>

#define WIDTH 10
#define MASK_WIDTH 3
#define TILE_WIDTH 4

__global__ void convolution(float *input, float *mask, float *output, int width, int mask_width) {
    __shared__ float tile[TILE_WIDTH + MASK_WIDTH - 1];

    int tx = threadIdx.x;
    int gx = blockIdx.x * blockDim.x + threadIdx.x;

    // Load tile from global memory into shared memory
    if (gx >= 0 && gx < width)
        tile[tx] = input[gx];
    else
        tile[tx] = 0;

    __syncthreads();

    float result = 0;
    for (int i = 0; i < mask_width; i++) {
        result += tile[tx + i] * mask[i];
    }

    // Write the result back to global memory
    if (gx >= 0 && gx < width)
        output[gx] = result;
}

int main() {
    float input[WIDTH] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    float mask[MASK_WIDTH] = {0.5, 1, 0.5};
    float output[WIDTH];

    float *d_input, *d_mask, *d_output;
    int size = WIDTH * sizeof(float);
    int mask_size = MASK_WIDTH * sizeof(float);

    // Allocate memory on device
    cudaMalloc((void **)&d_input, size);
    cudaMalloc((void **)&d_mask, mask_size);
    cudaMalloc((void **)&d_output, size);

    // Copy data from host to device
    cudaMemcpy(d_input, input, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_mask, mask, mask_size, cudaMemcpyHostToDevice);

    // Launch kernel
    convolution<<<1, WIDTH>>>(d_input, d_mask, d_output, WIDTH, MASK_WIDTH);

    // Copy result back to host
    cudaMemcpy(output, d_output, size, cudaMemcpyDeviceToHost);

    // Free device memory
    cudaFree(d_input);
    cudaFree(d_mask);
    cudaFree(d_output);

    // Display result
    printf("Convolution Result:\n");
    for (int i = 0; i < WIDTH; i++) {
        printf("%.2f ", output[i]);
    }
    printf("\n");

    return 0;
}
