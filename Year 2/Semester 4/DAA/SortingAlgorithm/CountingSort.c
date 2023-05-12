//COunting sort in c
#include<stdio.h>
void countingSort(int arr[],int n){
    int i,j,max=arr[0],min=arr[0];
    for(i=1;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            min=arr[i];
        }
    }
    int range=max-min+1;
    int count[range];
    for(i=0;i<range;i++){
        count[i]=0;
    }
    for(i=0;i<n;i++){
        count[arr[i]-min]++;
    }
    i=0;
    j=0;
    while(i<range){
        if(count[i]>0){
            arr[j++]=i+min;
            count[i]--;
        }
        else{
            i++;
        }
    }
}
int main(){
    int arr[]={5,1,3,9,2,10};
    int n=6;
    countingSort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
// Time Complexity: O(n+k) where k is the range of input.