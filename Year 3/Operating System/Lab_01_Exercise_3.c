#include <stdio.h>
#include <stdlib.h>
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
    for(int i=0;i<p;i++){
        for(int j=0;j<p;j++){
            if(arr[i]<arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
    }
    }
    for(int i=0;i<p;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}