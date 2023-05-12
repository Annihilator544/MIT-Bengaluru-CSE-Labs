// Exhaustive Search in c
#include<stdio.h>
int main(){
    int arr[]={5,1,3,9,2,10};
    int n=6;
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
// Time Complexity: O(n^2)