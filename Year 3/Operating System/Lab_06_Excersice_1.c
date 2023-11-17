#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *ptr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    ptr = (int*) malloc(n * sizeof(int));

    if (ptr == NULL) {
        printf("Error: Memory allocation failed.");
        exit(1);
    }

    printf("Memory allocation successful.\n");

    // Use the allocated memory here

    free(ptr);

    return 0;
}
