#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <mpi.h>

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    int rank, size, N;
    int *array;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        printf("Enter the number of elements in the array: ");
        scanf("%d", &N);

        array = (int *)malloc(N * sizeof(int));
        printf("Enter %d elements:\n", N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &array[i]);
        }
    }

    // Broadcast the value of N to all processes
    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // Scatter the array to all processes
    int *localArray = (int *)malloc(N / size * sizeof(int));
    MPI_Scatter(array, N / size, MPI_INT, localArray, N / size, MPI_INT, 0, MPI_COMM_WORLD);

    // Check if each element in the local array is prime
    for (int i = 0; i < N / size; i++) {
        bool prime = isPrime(localArray[i]);
        if (prime) {
            printf("Process %d: %d is prime.\n", rank, localArray[i]);
        } else {
            printf("Process %d: %d is not prime.\n", rank, localArray[i]);
        }
    }

    MPI_Finalize();
    return 0;
}
