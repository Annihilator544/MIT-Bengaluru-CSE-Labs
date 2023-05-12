//Depth first search in c
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void linkedListTraversal(struct Node *ptr){
    while(ptr!=NULL){
        printf(" %d ",ptr->data);
        ptr=ptr->next;
    }
}
int isEmpty(int *indegree,int n){
    int i;
    for(i=0;i<n;i++){
        if(indegree[i]!=0){
            return 0;
        }
    }
    return 1;
}
void topologicalSort(int **adjMat,int *indegree,int n){
    int i,j;
    struct Node *head=NULL;
    struct Node *tail=NULL;
    for(i=0;i<n;i++){
        if(indegree[i]==0){
            struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
            newNode->data=i;
            newNode->next=NULL;
            if(head==NULL){
                head=newNode;
                tail=newNode;
            }
            else{
                tail->next=newNode;
                tail=tail->next;
            }
        }
    }
    while(head!=NULL){
        int u=head->data;
        head=head->next;
        printf("%d ",u);
        for(j=0;j<n;j++){
            if(adjMat[u][j]==1){
                indegree[j]--;
                if(indegree[j]==0){
                    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
                    newNode->data=j;
                    newNode->next=NULL;
                    if(head==NULL){
                        head=newNode;
                        tail=newNode;
                    }
                    else{
                        tail->next=newNode;
                        tail=tail->next;
                    }
                }
            }
        }
    }
}
int main(){
    int n,i,j;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    int **adjMat=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++){
        adjMat[i]=(int *)malloc(n*sizeof(int));
    }
    printf("Enter the adjacency matrix: \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&adjMat[i][j]);
        }
    }
    int *indegree=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        indegree[i]=0;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(adjMat[j][i]==1){
                indegree[i]++;
            }
        }
    }
    printf("The topological sort of the graph is: ");
    topologicalSort(adjMat,indegree,n);
    return 0;
}
