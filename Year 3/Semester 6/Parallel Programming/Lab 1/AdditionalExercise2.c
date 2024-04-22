#include <mpi.h>
#include <stdio.h>
#include <math.h>

int is_prime(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(int argc, char** argv) {
    MPI_Init(NULL, NULL);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int start = world_rank * 50 + 1;
    int end = start + 99;

    printf("Process %d checking range %d to %d\n", world_rank, start, end);

    for (int i = start; i < end; i++) {
        if (is_prime(i)) {
            printf("%d is prime\n", i);
        }
    }

    MPI_Finalize();
    return 0;
}
