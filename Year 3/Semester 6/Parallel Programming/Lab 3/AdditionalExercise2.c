#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int rank, size;
    int N;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    if(rank == 0) {
        printf("Enter the size of array (N): ");
        scanf("%d", &N);
    }

    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if(N % size != 0) {
        if(rank == 0)
            printf("Error: N should be evenly divisible by the number of processes.\n");
        MPI_Finalize();
        return 0;
    }

    int *A = (int *)malloc(N * sizeof(int));

    if(rank == 0) {
        printf("Enter %d elements of array A:\n", N);
        for(int i = 0; i < N; i++)
            scanf("%d", &A[i]);
    }

    MPI_Bcast(A, N, MPI_INT, 0, MPI_COMM_WORLD);

    int count_even = 0;
    int count_odd = 0;

    // Replace even elements with 1 and odd elements with 0
    for(int i = 0; i < N; i++) {
        if(A[i] % 2 == 0)
            A[i] = 1;
        else
            A[i] = 0;

        if(A[i] == 1)
            count_even++;
        else
            count_odd++;
    }

    // Gather counts of even and odd numbers to root process
    int *counts = (int *)malloc(2 * sizeof(int));
    MPI_Gather(&count_even, 1, MPI_INT, counts, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Gather(&count_odd, 1, MPI_INT, counts+1, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if(rank == 0) {
        printf("Resultant Array (A): ");
        for(int i = 0; i < N; i++)
            printf("%d ", A[i]);
        printf("\n");
        
        int total_even = 0;
        int total_odd = 0;
        for(int i = 0; i < size; i++) {
            total_even += counts[i];
            total_odd += counts[size + i];
        }
        printf("Even (Count) = %d\n", total_even);
        printf("Odd (Count) = %d\n", total_odd);
    }

    free(A);
    free(counts);

    MPI_Finalize();
    return 0;
}
