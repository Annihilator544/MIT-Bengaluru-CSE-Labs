//array in c
#include<stdio.h>  
int main(){
    int arr[5];//declaration of array
    int i;
    printf("Enter the elements of the array\n");
    for(i=0;i<5;i++){
        scanf("%d",&arr[i]);
    }
    printf("The elements of the array are\n");
    for(i=0;i<5;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}