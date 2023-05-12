//Brute force string matcjhin algorithm
#include<stdio.h>
#include<string.h>
int main(){
    char text[100],pattern[100];
    printf("Enter the text\n");
    gets(text);
    printf("Enter the pattern\n");
    gets(pattern);
    int n=strlen(text);
    int m=strlen(pattern);
    int i,j;
    for(i=0;i<=n-m;i++){
        for(j=0;j<m;j++){
            if(text[i+j]!=pattern[j]){
                break;
            }
        }
        if(j==m){
            printf("Pattern found at index %d\n",i);
        }
    }
    return 0;
}
// Time Complexity: O((n-m+1)*m)