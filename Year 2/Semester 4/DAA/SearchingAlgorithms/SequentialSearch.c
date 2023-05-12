//Sequential search algorithm
#include<stdio.h>
int sequentialSearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[]={5,1,3,9,2,10};
    int n=6;
    int key=9;
    int index=sequentialSearch(arr,n,key);
    if(index==-1){
        printf("Element not found\n");
    }
    else{
        printf("Element found at index %d\n",index);
    }
    return 0;
}
// Time Complexity: O(n)