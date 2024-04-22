#include <stdio.h>
#include <math.h>

#define N 4
#define THREADS_PER_BLOCK 256

__global__ void computeSine(float *angles, float *sineValues, int n) {
    int index = threadIdx.x + blockIdx.x * blockDim.x;
    if (index < n) {
        sineValues[index] = sinf(angles[index]);
    }
}

int main() {
    float angles[N], sineValues[N];
    float *dev_angles, *dev_sineValues;

    // Initialize input array with angles in radians
    for (int i = 0; i < N; ++i) {
        angles[i] = i * (3.14159 / N);  // Converting to radians from 0 to pi
    }

    // Allocate device memory
    cudaMalloc((void **)&dev_angles, N * sizeof(float));
    cudaMalloc((void **)&dev_sineValues, N * sizeof(float));

    // Copy data from host to device
    cudaMemcpy(dev_angles, angles, N * sizeof(float), cudaMemcpyHostToDevice);

    // Define block size and grid size
    int blockSize = THREADS_PER_BLOCK;
    int gridSize = (N + blockSize - 1) / blockSize;

    // Perform computation on GPU
    computeSine<<<gridSize, blockSize>>>(dev_angles, dev_sineValues, N);

    // Copy result back to host
    cudaMemcpy(sineValues, dev_sineValues, N * sizeof(float), cudaMemcpyDeviceToHost);

    // Free device memory
    cudaFree(dev_angles);
    cudaFree(dev_sineValues);

    // Display the result
    printf("Angle (radians)\tSine Value\n");
    for (int i = 0; i < N; ++i) {
        printf("%f\t%f\n", angles[i], sineValues[i]);
    }

    return 0;
}
