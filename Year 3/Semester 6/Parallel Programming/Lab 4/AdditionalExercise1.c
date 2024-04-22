#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size, N;
    char input_word[100];
    char output_word[100];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        printf("Enter a word: ");
        scanf("%s", input_word);
        N = strlen(input_word);
    }

    // Broadcast the length of the word to all processes
    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // Scatter the input word to all processes
    MPI_Bcast(input_word, N, MPI_CHAR, 0, MPI_COMM_WORLD);

    // Calculate the start index and length for each process
    int start_index = rank * (N * (N + 1) / 2);
    int length = (N * (N + 1) / 2) - (rank * (N * (N - 1) / 2));

    // Construct the output word according to the pattern
    int pos = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            output_word[start_index + pos++] = input_word[i];
        }
    }
    output_word[start_index + length] = '\0';

    // Gather all output words in the root process
    char *gathered_output = NULL;
    if (rank == 0) {
        gathered_output = (char *)malloc((N * (N + 1) / 2 + size) * sizeof(char));
    }
    MPI_Gather(output_word, length + 1, MPI_CHAR, gathered_output, length + 1, MPI_CHAR, 0, MPI_COMM_WORLD);

    // Display the result in the root process
    if (rank == 0) {
        printf("Output: %s\n", gathered_output);
        free(gathered_output);
    }

    MPI_Finalize();
    return 0;
}
