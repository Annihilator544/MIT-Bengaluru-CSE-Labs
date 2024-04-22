#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

__global__ void repeatString(char *inputString, char *outputString, int stringLength) {
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    if (tid < stringLength) {
        int count = 0;
        for(int i=0 ;i<stringLength;i++){
        for(int j=0 ;j<i+1;j++){
            outputString[count] = inputString[i];
            count++;
        }}
    }
}

int main() {
    char inputString[MAX_STRING_LENGTH];
    char outputString[MAX_STRING_LENGTH * 3]; // Adjusted for triple length
    char *d_inputString, *d_outputString;
    int stringLength;

    printf("Enter a string: ");
    fgets(inputString, MAX_STRING_LENGTH, stdin);
    // Remove newline character if present
    if (inputString[strlen(inputString) - 1] == '\n') {
        inputString[strlen(inputString) - 1] = '\0';
    }

    stringLength = strlen(inputString);

    // Allocate memory for inputString and outputString on device
    cudaMalloc((void **)&d_inputString, stringLength * sizeof(char));
    cudaMalloc((void **)&d_outputString, stringLength * 3 * sizeof(char)); // Triple length

    // Copy inputString to device
    cudaMemcpy(d_inputString, inputString, stringLength * sizeof(char), cudaMemcpyHostToDevice);

    // Calculate the number of blocks needed
    int numBlocks = (stringLength + 255) / 256;

    // Launch kernel
    repeatString<<<numBlocks, 256>>>(d_inputString, d_outputString, stringLength);

    // Copy outputString back to host
    cudaMemcpy(outputString, d_outputString, stringLength * 3 * sizeof(char), cudaMemcpyDeviceToHost); // Triple length

    // Cleanup
    cudaFree(d_inputString);
    cudaFree(d_outputString);

    // Display result
    printf("Input string S:   %s\n", inputString);
    printf("Output string RS:  %s\n", outputString);

    return 0;
}
