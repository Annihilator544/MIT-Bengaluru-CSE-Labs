#include <stdio.h>
#include <math.h>
#include <mpi.h>

int main(int argc, char* argv[]) {
    int rank, size;
    int x = 2; // Change this to your desired integer constant

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    double result = pow(x, rank);

    printf("Process %d: pow(%d, %d) = %f\n", rank, x, rank, result);

    MPI_Finalize();
    return 0;
}