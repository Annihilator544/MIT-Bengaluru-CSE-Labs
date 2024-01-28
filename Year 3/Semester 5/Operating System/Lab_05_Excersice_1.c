#include<stdio.h> 
#include<stdlib.h> 
#include<pthread.h> 
void* generate_fibonacci(void* param)  
{ 

int* arr = (int*)param; 
int n = arr[0]; 
arr[1] = 0; 
arr[2] = 1; 
for(int i = 3;i <= n;i++)  
{ 
    arr[i] = arr[i-1] + arr[i-2];
} 
 
return NULL; 
}
int main(int argc, char const *argv[]) 
{ 
int n; 
printf("Enter no of Fibonacci numbers : \n"); 
scanf("%d",&n); 
int* arr = (int*)malloc((n+1)*sizeof(int)); 
arr[0] = n; 
pthread_t thread; 
pthread_create(&thread,0,&generate_fibonacci,(void*)arr); 
pthread_join(thread,0); 
for(int i = 1;i <= n;i++) 
printf("%d ",arr[i]); 
printf("\n"); 
return 0; 
}