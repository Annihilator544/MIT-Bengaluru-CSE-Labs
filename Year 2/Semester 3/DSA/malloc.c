#include <stdio.h>
#include <stdlib.h>
int main() {
   int i,*ptr,n;
   printf("Enter number of elements:");
    scanf("%d",&n);
    ptr = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }
        printf("The elements of the array are:\n ");
        for (i = 0; i < n; ++i) {
            printf("%d\n ", ptr[i]);
        }
        ptr = realloc(ptr, 15);
        for (i = 0; i < 15; ++i) {
            ptr[i] = i + 1;
        }
        printf("The elements of the array are:\n ");
        for (i = 0; i < 15; ++i) {
            printf("%d\n ", ptr[i]);
        }
        free(ptr);
    return 0;
}
