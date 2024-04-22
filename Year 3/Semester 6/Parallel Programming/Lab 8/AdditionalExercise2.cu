#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1024
#define MAX_OUTPUT_LENGTH (MAX_STRING_LENGTH * 10) // Maximum output length assuming N up to 10
#define THREADS_PER_BLOCK 256

__global__ void concatenateStrings(const char *inputString, int inputLength, char *outputString, int N) {
    int tid = blockIdx.x * blockDim.x + threadIdx.x;

    if (tid < inputLength * N) {
        int inputIndex = tid % inputLength;
        outputString[tid] = inputString[inputIndex];
    }
}

int main() {
    const char *inputString = "Hello";
    int N = 3;

    char *d_inputString, *d_outputString;
    int inputLength = strlen(inputString);
    int outputLength = inputLength * N;
    char outputString[MAX_OUTPUT_LENGTH];

    // Allocate memory for inputString and outputString on device
    cudaMalloc((void **)&d_inputString, inputLength * sizeof(char));
    cudaMalloc((void **)&d_outputString, outputLength * sizeof(char));

    // Copy inputString to device
    cudaMemcpy(d_inputString, inputString, inputLength * sizeof(char), cudaMemcpyHostToDevice);

    int numBlocks = (outputLength + THREADS_PER_BLOCK - 1) / THREADS_PER_BLOCK;

    // Launch kernel to concatenate strings
    concatenateStrings<<<numBlocks, THREADS_PER_BLOCK>>>(d_inputString, inputLength, d_outputString, N);

    // Copy outputString back to host
    cudaMemcpy(outputString, d_outputString, outputLength * sizeof(char), cudaMemcpyDeviceToHost);

    // Null-terminate the output string
    outputString[outputLength] = '\0';

    // Cleanup
    cudaFree(d_inputString);
    cudaFree(d_outputString);

    // Display result
    printf("Input string Sin:   %s\n", inputString);
    printf("N:                   %d\n", N);
    printf("Output string Sout:  %s\n", outputString);

    return 0;
}
