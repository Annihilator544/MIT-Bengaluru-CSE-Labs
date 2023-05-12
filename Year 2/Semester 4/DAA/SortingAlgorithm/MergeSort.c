//Merge Sort in c
#include<stdio.h>
void merge(int arr[],int l,int mid,int h){
    int i=l,j=mid+1,k=l;
    int b[100];
    while(i<=mid && j<=h){
        if(arr[i]<arr[j]){
            b[k++]=arr[i++];
        }
        else{
            b[k++]=arr[j++];
        }
    }
    for(;i<=mid;i++){
        b[k++]=arr[i];
    }
    for(;j<=h;j++){
        b[k++]=arr[j];
    }
    for(i=l;i<=h;i++){
        arr[i]=b[i];
    }
}
void mergeSort(int arr[],int l,int h){
    int mid;
    if(l<h){
        mid=(l+h)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}
int main(){
    int arr[]={5,1,3,9,2,10};
    int n=6;
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
// Time Complexity: O(nlogn)