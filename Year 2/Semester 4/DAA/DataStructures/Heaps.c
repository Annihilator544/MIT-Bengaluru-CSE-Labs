//heaps in c
#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int arr[],int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    int temp;
    if(l<n && arr[l]>arr[largest]){
        largest=l;
    }
    if(r<n && arr[r]>arr[largest]){
        largest=r;
    }
    if(largest!=i){
        //swap arr[i] and arr[largest]
        swap(&arr[i],&arr[largest]);
        heapify(arr,n,largest);
    }
}
void buildHeap(int arr[],int n){
    int i;
    for(i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
}
void printHeap(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[]={5,1,3,9,2,10};
    int n=6;
    buildHeap(arr,n);
    printHeap(arr,n);
    return 0;
}
// // Time Complexity: O(n)