#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

#define N 5

void print_matrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size != N) {
        if (rank == 0) {
            printf("This program needs to be run with %d processes.\n", N);
        }
        MPI_Finalize();
        return 0;
    }

    int A[N][N], B[N][N];
    int max_col[N], min_col[N];
    int local_row[N];

    if (rank == 0) {
        // Initialize matrix A with random values
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                A[i][j] = rand() % 100;
            }
        }

        printf("Matrix A:\n");
        print_matrix(A);
    }

    // Distribute rows of A to all processes
    MPI_Scatter(A, N, MPI_INT, local_row, N, MPI_INT, 0, MPI_COMM_WORLD);

    // Each process finds the max and min of its row
    max_col[rank] = min_col[rank] = local_row[0];
    for (int j = 1; j < N; j++) {
        if (local_row[j] > max_col[rank]) {
            max_col[rank] = local_row[j];
        }
        if (local_row[j] < min_col[rank]) {
            min_col[rank] = local_row[j];
        }
    }

    // Gather max and min of each row in all processes
    MPI_Allgather(MPI_IN_PLACE, 0, MPI_DATATYPE_NULL, max_col, 1, MPI_INT, MPI_COMM_WORLD);
    MPI_Allgather(MPI_IN_PLACE, 0, MPI_DATATYPE_NULL, min_col, 1, MPI_INT, MPI_COMM_WORLD);

    // Each process creates its row of B
    for (int j = 0; j < N; j++) {
        if (j < rank) {
            B[rank][j] = max_col[j];
        } else if (j > rank) {
            B[rank][j] = min_col[j];
        } else {
            B[rank][j] = 0;
        }
    }

    // Gather B in process 0
    MPI_Gather(B[rank], N, MPI_INT, B, N, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Matrix B:\n");
        print_matrix(B);
    }

    MPI_Finalize();
    return 0;
}
