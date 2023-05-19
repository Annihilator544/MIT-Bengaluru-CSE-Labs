//n queen problem using backtracking algorithm
#include<stdio.h>
#include<math.h>
int x[10];
int place(int k,int i){
    for(int j=1;j<=k-1;j++){
        if(x[j]==i || abs(x[j]-i)==abs(j-k)){
            return 0;
        }
    }
    return 1;
}
void nQueen(int k,int n){
    for(int i=1;i<=n;i++){
        if(place(k,i)){
            x[k]=i;
            if(k==n){
                for(int j=1;j<=n;j++){
                    printf("%d ",x[j]);
                }
                printf("\n");
            }
            else{
                nQueen(k+1,n);
            }
        }
    }
}
int main(){
    int n=4;
    nQueen(1,n);
    return 0;
}
// Time Complexity: O(n!)