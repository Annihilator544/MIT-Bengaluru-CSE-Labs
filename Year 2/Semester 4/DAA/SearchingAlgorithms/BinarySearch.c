// Binary Search in c
#include<stdio.h>
int binarySearch(int arr[],int n,int key){
    int low=0,high=n-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(key==arr[mid]){
            return mid;
        }
        else if(key<arr[mid]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n=10;
    int key=5;
    int index=binarySearch(arr,n,key);
    if(index==-1){
        printf("Element not found");
    }
    else{
        printf("Element found at index %d",index);
    }
    return 0;
}
// Time Complexity: O(log n)