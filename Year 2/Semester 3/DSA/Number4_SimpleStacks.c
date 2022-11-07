#include<stdio.h>
#include<stdlib.h>

int n, top = -1, *stack,i,k=1,l;

void push(int x){
	if(top==n-1)printf("Stack overflow\n");
	else
	stack[++top]=x;
}

int pop(){
	if(top==-1)printf("Stack underflow\n");
	else
	return stack[top--];
}

int peek(){
	if(top==-1) return -1;
	printf("%d\n", stack[top]);
    return 0;
}

void display(){
	for(i=0 ; i<=top ; i++) printf("%d ",stack[i]);
	printf("\n\n");
}

int main(){
    printf("Enter the size of the stack :");
    scanf("%d",&n);
	printf("Initializing the stack with size %d\n\n",n);

	stack = (int*)malloc((n)*sizeof(int));

	printf("Pushing elements into the stack\n");
	for(i=0;i<n;i++){
     int j;
     printf("Enter element : ");
     scanf("%d",&j);
     push(j);
	}

	printf("Displaying elements of the stack -\n");

	display();
    printf("Press Number for following operations :\n1. Push\n2. Pop\n3. Peek\n");
    while(k>0){
        printf("Enter Operation : ");
        scanf("%d",&l);
        switch(l){
            case 1 :
               printf("Enter element : ");
                scanf("%d",&i);
                push(i);
                break;
            case 2 :
                pop();
                break;
            case 3 :
                peek();
                break;
        }
        display();
    }


	return 0;
}
