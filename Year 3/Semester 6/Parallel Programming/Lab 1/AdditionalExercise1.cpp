//mpicc -o AdditionalExercise AdditionalExercise1.cpp
// mpiexec -n 5 ./AdditionalExercise

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int reverse(int num) {
    int rev = 0;
    while (num > 0) {
        rev = rev * 10 + num % 10;
        num = num / 10;
    }
    return rev;
}

int main(int argc, char* argv[]) {
    int size, rank;
    int array[9] = { 18, 523, 301, 1234, 2, 14, 108, 150, 1928 };
    int rev_array[9];

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    for(int i=0; i<9;i++){
        rev_array[i] = reverse(array[i]);
    }
    if (rank == 0) {
        printf("Reversed array: ");
        for (int i = 0; i < 9; i++) {
            printf("%d ", rev_array[i]);
        }
        printf("\n");
    }

    MPI_Finalize();
    return 0;
}
