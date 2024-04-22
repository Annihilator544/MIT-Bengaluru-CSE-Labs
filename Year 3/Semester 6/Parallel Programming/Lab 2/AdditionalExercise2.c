#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

// Function to calculate factorial
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main(int argc, char *argv[]) {
    int rank, size, N;
    int partial_sum = 0;
    int total_sum = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        printf("Enter the value of N: ");
        scanf("%d", &N);
    }

    // Broadcast the value of N to all processes
    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // Each process calculates its partial sum
    for (int i = rank + 1; i <= N; i += size) {
        int factorial_result = factorial(i);
        int sum = 0;
        for (int j = 1; j <= i; j++) {
            sum += j;
        }
        partial_sum += factorial_result + sum;
    }

    // Reduce all partial sums to root process
    MPI_Reduce(&partial_sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Result: %d\n", total_sum);
    }

    MPI_Finalize();
    return 0;
}
