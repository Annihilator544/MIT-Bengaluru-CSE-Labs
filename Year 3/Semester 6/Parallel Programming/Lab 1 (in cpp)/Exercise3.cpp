#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size;
    int operation, num1, num2;
    int result = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        // Process 0 takes input from user
        printf("Enter operation (1: Addition, 2: Subtraction, 3: Multiplication, 4: Division): ");
        scanf("%d", &operation);
        printf("Enter first number: ");
        scanf("%d", &num1);
        printf("Enter second number: ");
        scanf("%d", &num2);
    }

    // Broadcast operation, num1, and num2 to all processes
    MPI_Bcast(&operation, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&num1, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&num2, 1, MPI_INT, 0, MPI_COMM_WORLD);

    switch(operation) {
        case 1: // Addition
            result = num1 + num2;
            printf("Result: %d\n", result);
            break;
        case 2: // Subtraction
            result = num1 - num2;
            printf("Result: %d\n", result);
            break;
        case 3: // Multiplication
            result = num1 * num2;
            printf("Result: %d\n", result);
            break;
        case 4: // Division
            if (num2 != 0) {
                result = num1 / num2;
                printf("Result: %d\n", result);
            } else {
                printf("Error: Division by zero!\n");
            }
            break;
        default:
            if (rank == 0) {
                printf("Error: Invalid operation!\n");
            }
            break;
    }

    MPI_Finalize();
    return 0;
}
