#include <stdio.h>

#define MAX_ITEMS 5
#define MAX_FRIENDS 3

__global__ void calculateTotalPurchase(float *prices, int *purchases, float *total) {
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    atomicAdd(total, prices[tid] * purchases[tid]);
}

int main() {
    float prices[MAX_ITEMS] = {10.5, 20.25, 15.75, 8.0, 12.5};
    int purchases[MAX_ITEMS * MAX_FRIENDS] = {2, 1, 0, 3, 1, 2, 0, 1, 2, 3, 0, 1};  // Example purchases by each friend
    float totalPurchase = 0.0;

    float *d_prices, *d_total;
    int *d_purchases;
    int itemsSize = MAX_ITEMS * sizeof(float);
    int friendsSize = MAX_ITEMS * MAX_FRIENDS * sizeof(int);

    // Allocate memory on device
    cudaMalloc((void **)&d_prices, itemsSize);
    cudaMalloc((void **)&d_purchases, friendsSize);
    cudaMalloc((void **)&d_total, sizeof(float));

    // Copy data from host to device
    cudaMemcpy(d_prices, prices, itemsSize, cudaMemcpyHostToDevice);
    cudaMemcpy(d_purchases, purchases, friendsSize, cudaMemcpyHostToDevice);
    cudaMemset(d_total, 0, sizeof(float));  // Initialize total to 0 on device

    // Launch kernel
    calculateTotalPurchase<<<1, MAX_ITEMS>>>(d_prices, d_purchases, d_total);

    // Copy result back from device to host
    cudaMemcpy(&totalPurchase, d_total, sizeof(float), cudaMemcpyDeviceToHost);

    // Display result
    printf("Total Purchase by %d friends: $%.2f\n", MAX_FRIENDS, totalPurchase);

    // Free device memory
    cudaFree(d_prices);
    cudaFree(d_purchases);
    cudaFree(d_total);

    return 0;
}
