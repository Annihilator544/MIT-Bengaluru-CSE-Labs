#include<stdio.h>
# define MAX 5

int c_arr[MAX];
int front = -1;
int rear = -1;
void insert(int item)
{
if((front == 0 && rear == MAX-1) || (front == rear+1))
{
printf("Queue Overflow \n");
return;
}
if(front == -1)
{
front = 0;
rear = 0;
}
else
{
if(rear == MAX-1)
rear = 0;
else
rear = rear+1;
}
c_arr[rear] = item ;
}
void deletion()
{
if(front == -1)
{
printf("Queue Underflow \n");
return ;
}
printf("Element deleted from queue is : %d \n",c_arr[front]);
if(front == rear)
{
front = -1;
rear=-1;
}
else
{
if(front == MAX-1)
front = 0;
else
front = front+1;
}
}
void display()
{
int fpos = front,rpos = rear;
if(front == -1)
{
printf("Queue is empty \n");
return;
}
printf("Queue elements : \n");
if( fpos <= rpos )
while(fpos <= rpos)
{
printf("%d ",c_arr[fpos]);
fpos++;
}
else
{
while(fpos <= MAX-1)
{
printf("%d ",c_arr[fpos]);
fpos++;
}
fpos = 0;
while(fpos <= rpos)
{
printf("%d ",c_arr[fpos]);
fpos++;
}
}
printf("\n");
}
int main()
{
int ch,item;
printf("1.Insert \n");
printf("2.Delete \n");
printf("3.Display \n");
printf("4.Quit \n");
do
{
printf("Enter your choice : ");
scanf("%d",&ch);
switch(ch)
{
case 1 :
printf("Input the element : \n");
scanf("%d", &item);
insert(item);
break;
case 2 :
deletion();
break;
case 3:
display();
break;
case 4:
break;
default:
printf("Wrong choice \n");
}
}while(ch!=4);
return 0;
}
