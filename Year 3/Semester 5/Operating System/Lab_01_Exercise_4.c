#include<stdio.h>
#include<stdlib.h>
int main(){
    printf("Enter the Numbers u want to read !\n");
    int n;
    scanf("%d",&n);
    int p=n;
    int arr[n];
    while(n>0){ // while(n>0)
        int x;
        scanf("%d",&arr[p-n]);
        n--;
    }
    printf("Enter the Numbers u want to search !\n");
    int q;
    scanf("%d",&q);
    for(int i=0;i<p;i++){
        if(arr[i]==q){
            printf("Found at %d\n",i);
            return 0;
        }
    }
    printf("Not Found !\n");
    return 0;
}