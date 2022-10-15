#include <stdio.h>
int sum=0;
int main(){
    int n;
    printf("Give Me A Number !!!!! ");
    scanf("%d",&n);

    printf("Reversed Number Is : %d",numberreverser(n));
}
int numberreverser(int a){
sum=sum*10+a%10;
a=a/10;
if(a!=0){
    numberreverser(a);
}
else{
    return (sum);
}
}
