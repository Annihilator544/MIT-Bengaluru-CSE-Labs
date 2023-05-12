//dynamic memory queue with user input in c
#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int f;
    int r;
    int *arr;
};
int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(struct queue *q,int val){
    if(isFull(q)){
        printf("Queue Overflow! Cannot enqueue %d to the queue\n",val);
    }
    else{
        q->r++;
        q->arr[q->r]=val;
    }
}
int dequeue(struct queue *q){
    if(isEmpty(q)){
        printf("Queue Underflow! Cannot dequeue from the queue\n");
        return -1;
    }
    else{
        q->f++;
        int val=q->arr[q->f];
        return val;
    }
}
int main(){
    struct queue q;
    q.size=100;
    q.f=q.r=-1;
    q.arr=(int *)malloc(q.size*sizeof(int));
    enqueue(&q,12);
    enqueue(&q,15);
    enqueue(&q,1);
    enqueue(&q,45);
    enqueue(&q,80);
    enqueue(&q,90);
    
    printf("Dequeuing element %d\n",dequeue(&q));
    printf("Dequeuing element %d\n",dequeue(&q));
    printf("Dequeuing element %d\n",dequeue(&q));
    printf("Dequeuing element %d\n",dequeue(&q));
    printf("Dequeuing element %d\n",dequeue(&q));
    printf("Dequeuing element %d\n",dequeue(&q));
    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    if(isFull(&q)){
        printf("Queue is full\n");
    }
    return 0;
}
