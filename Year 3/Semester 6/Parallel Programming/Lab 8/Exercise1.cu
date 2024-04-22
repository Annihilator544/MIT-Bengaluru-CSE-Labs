#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000
#define MAX_WORD_LENGTH 50

__global__ void countWord(char *sentence, char *word, int *count, int sentenceLength, int wordLength) {
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    if (tid < sentenceLength) {
        if (tid + wordLength <= sentenceLength) {
            int match = 1;
            for (int i = 0; i < wordLength; i++) {
                if (sentence[tid + i] != word[i]) {
                    match = 0;
                    break;
                }
            }
            if (match == 1) {
                atomicAdd(count, 1);
            }
        }
    }
}

int main() {
    char sentence[MAX_STRING_LENGTH];
    char word[MAX_WORD_LENGTH];
    int *d_count, *count;
    int sentenceLength, wordLength, countValue = 0;
    char *d_sentence, *d_word;

    printf("Enter a sentence: ");
    fgets(sentence, MAX_STRING_LENGTH, stdin);
    // Remove newline character if present
    if (sentence[strlen(sentence) - 1] == '\n') {
        sentence[strlen(sentence) - 1] = '\0';
    }

    printf("Enter the word to count: ");
    scanf("%s", word);

    sentenceLength = strlen(sentence);
    wordLength = strlen(word);

    // Allocate memory for count on host and device
    count = (int *)malloc(sizeof(int));
    cudaMalloc((void **)&d_count, sizeof(int));
    cudaMemcpy(d_count, &countValue, sizeof(int), cudaMemcpyHostToDevice);

    // Allocate memory for sentence and word on device
    cudaMalloc((void **)&d_sentence, sentenceLength * sizeof(char));
    cudaMalloc((void **)&d_word, wordLength * sizeof(char));
    cudaMemcpy(d_sentence, sentence, sentenceLength * sizeof(char), cudaMemcpyHostToDevice);
    cudaMemcpy(d_word, word, wordLength * sizeof(char), cudaMemcpyHostToDevice);

    // Calculate the number of blocks needed
    int numBlocks = (sentenceLength + 255) / 256;

    // Launch kernel
    countWord<<<numBlocks, 256>>>(d_sentence, d_word, d_count, sentenceLength, wordLength);

    // Copy count back to host
    cudaMemcpy(&countValue, d_count, sizeof(int), cudaMemcpyDeviceToHost);

    // Cleanup
    free(count);
    cudaFree(d_count);
    cudaFree(d_sentence);
    cudaFree(d_word);

    // Display result
    printf("Number of occurrences of '%s' in the sentence: %d\n", word, countValue);

    return 0;
}