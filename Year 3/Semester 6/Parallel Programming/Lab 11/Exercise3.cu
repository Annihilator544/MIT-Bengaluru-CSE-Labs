#include <stdio.h>

#define N 10

__global__ void inclusiveScan(int *input, int *output) {
    __shared__ int temp[N * 2];

    int tx = threadIdx.x;
    int offset = 1;

    temp[2 * tx] = input[2 * tx];
    temp[2 * tx + 1] = input[2 * tx + 1];

    for (int d = N >> 1; d > 0; d >>= 1) {
        __syncthreads();

        if (tx < d) {
            int ai = offset * (2 * tx + 1) - 1;
            int bi = offset * (2 * tx + 2) - 1;
            temp[bi] += temp[ai];
        }
        offset *= 2;
    }

    if (tx == 0) {
        temp[N * 2 - 1] = 0; // Set the last element to 0 for exclusive scan
    }

    for (int d = 1; d < N * 2; d *= 2) {
        offset >>= 1;
        __syncthreads();

        if (tx < d) {
            int ai = offset * (2 * tx + 1) - 1;
            int bi = offset * (2 * tx + 2) - 1;
            int t = temp[ai];
            temp[ai] = temp[bi];
            temp[bi] += t;
        }
    }

    __syncthreads();

    output[2 * tx] = temp[2 * tx];
    output[2 * tx + 1] = temp[2 * tx + 1];
}

int main() {
    int input[N] = {3, 1, 7, 0, 4, 1, 6, 3, 2, 5};
    int output[N];

    int *d_input, *d_output;
    int size = N * sizeof(int);

    // Allocate memory on device
    cudaMalloc((void **)&d_input, size);
    cudaMalloc((void **)&d_output, size);

    // Copy input data from host to device
    cudaMemcpy(d_input, input, size, cudaMemcpyHostToDevice);

    // Launch kernel
    inclusiveScan<<<1, N/2>>>(d_input, d_output);

    // Copy result back from device to host
    cudaMemcpy(output, d_output, size, cudaMemcpyDeviceToHost);

    // Display result
    printf("Input Array:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", input[i]);
    }
    printf("\n\nInclusive Scan Result:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");

    // Free device memory
    cudaFree(d_input);
    cudaFree(d_output);

    return 0;
}
