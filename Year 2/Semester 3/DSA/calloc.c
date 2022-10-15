#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* ptr;
    int n, i;
    printf("Enter number of elements: \n");
    scanf("%d",&n);
    ptr = (int*)calloc(n, sizeof(int));
    for (i = 0; i < n; ++i) {
        ptr[i] = i + 1;
    }
    printf("The elements of the array are:\n ");
    for (i = 0; i < n; ++i) {
        printf("%d\n ", ptr[i]);
    }
    free(ptr);
return 0;
}
