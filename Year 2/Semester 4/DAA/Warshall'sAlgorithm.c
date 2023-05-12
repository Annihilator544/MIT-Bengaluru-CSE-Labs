//Binomial coefficent computation using warshall's algorithm
#include<stdio.h>
int min(int a,int b){
    return a<b?a:b;
}
int main(){
    int n,k;
    printf("Enter the value of n and k\n");
    scanf("%d %d",&n,&k);
    int c[n+1][k+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=min(i,k);j++){
            if(j==0||j==i){
                c[i][j]=1;
            }
            else{
                c[i][j]=c[i-1][j-1]+c[i-1][j];
            }
        }
    }
    printf("The value of c(%d,%d) is %d",n,k,c[n][k]);
    return 0;
}
// Time Complexity: O(n*k)