#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("Enter the Numbers u want to read !\n");
    int n;
    scanf("%d",&n);
    while(n--){ // while(n>0)
        int x;
        scanf("%d",&x);
        printf("%d\n",x);
    }
    return 0;
}