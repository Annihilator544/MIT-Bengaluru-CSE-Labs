#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int rank, size;
    int M, N;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    if(rank == 0) {
        printf("Enter the value of M: ");
        scanf("%d", &M);
        N = size;
    }

    MPI_Bcast(&M, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);

    int *data = (int *)malloc(M * N * sizeof(int));

    if(rank == 0) {
        printf("Enter %d * %d elements:\n", N, M);
        for(int i = 0; i < M * N; i++)
            scanf("%d", &data[i]);
    }

    MPI_Bcast(data, M * N, MPI_INT, 0, MPI_COMM_WORLD);

    int *result = (int *)malloc(M * sizeof(int));

    // Compute squares, cubes, etc. based on process rank
    for(int i = 0; i < M; i++) {
	result[i] = data[rank * M + i];
	for(int j=0;j<rank+1;j++){
        	result[i] *= data[rank * M + i];}
    }

    int *final_result = NULL;
    if(rank == 0)
        final_result = (int *)malloc(M * N * sizeof(int));

    MPI_Gather(result, M, MPI_INT, final_result, M, MPI_INT, 0, MPI_COMM_WORLD);

    if(rank == 0) {
        printf("Results:\n");
        for(int i = 0; i < M * N; i++) {
            if(i % M == 0)
                printf("\n");
            printf("%d ", final_result[i]);
        }
        printf("\n");
    }

    free(data);
    free(result);
    if(rank == 0)
        free(final_result);

    MPI_Finalize();
    return 0;
}
