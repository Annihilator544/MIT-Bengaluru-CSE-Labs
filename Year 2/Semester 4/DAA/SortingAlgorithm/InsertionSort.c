//Insertion sort in c
#include<stdio.h>
void insertionSort(int arr[],int n){
    int i,j,x;
    for(i=1;i<n;i++){
        j=i-1;
        x=arr[i];
        while(j>-1 && arr[j]>x){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=x;
    }
}
int main(){
    int arr[]={5,1,3,9,2,10};
    int n=6;
    insertionSort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
// Time Complexity: O(n^2)