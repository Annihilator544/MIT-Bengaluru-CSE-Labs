#include <stdio.h>

#define N 10
#define BLOCK_SIZE 256

__global__ void oddEvenSort(int *arr, int n) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i < n) {
        int temp;
        if (i % 2 == 0) { // Even phase
            if (i < n - 1 && arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        } else { // Odd phase
            if (i > 0 && arr[i] < arr[i - 1]) {
                temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            }
        }
    }
}

int main() {
    int arr[N];

    // Initialize array with random values
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 10; // Random values between 0 and 999
    }

    int *d_arr;
    cudaMalloc((void**)&d_arr, N * sizeof(int));
    cudaMemcpy(d_arr, arr, N * sizeof(int), cudaMemcpyHostToDevice);

    dim3 blocks((N + BLOCK_SIZE - 1) / BLOCK_SIZE, 1, 1);
    dim3 threads(BLOCK_SIZE, 1, 1);

    // Perform odd-even sort in parallel
    for (int i = 0; i < N; i++) {
        oddEvenSort<<<blocks, threads>>>(d_arr, N);
        cudaDeviceSynchronize();
    }

    cudaMemcpy(arr, d_arr, N * sizeof(int), cudaMemcpyDeviceToHost);
    cudaFree(d_arr);

    // Print sorted array (for verification)
    printf("Sorted Array:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
