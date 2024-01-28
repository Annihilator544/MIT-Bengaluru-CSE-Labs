#include<stdio.h>  
#include<stdlib.h>  
#include<pthread.h>  
void* summation(void* param)  
{ 
int* arr = (int*)param;  
int sum = 0;  
int n = arr[0];  
for(int i = 1;i <= n;i++) 
{ 
if(arr[i] > 0) 
sum += arr[i]; 
}  
return (void*)sum;  
}  
int main(int argc, char const *argv[])  
{ 
int n;  
printf("Enter the no. of numbers : \n");  
scanf("%d",&n);  
int* arr = (int*)malloc((n+1)*sizeof(int));  
arr[0] = n; 
printf("Enter the numbers : \n");  
for(int i= 1;i <= n;i++) 
{ 
scanf("%d",&arr[i]); 
} 
int answer = 0;  
pthread_t thread;  
pthread_create(&thread,0,&summation,(void*)arr);  
pthread_join(thread,(void**)&answer);  
printf("Summation of non-negative numbers = %d\n",answer);  
return 0;  
} 