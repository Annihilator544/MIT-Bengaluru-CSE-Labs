// Breadth First Search Algorithm
// Breadth First Search (BFS) is a graph traversal algorithm where we start traversing from a source node and traverse the graph layerwise thus exploring the neighbour nodes (nodes which are directly connected to source node). We must remember that in graphs, there can be cycles and we can visit the same node again while traversing a graph. So, we must maintain a boolean array to mark visited nodes and avoid revisiting them.
// Algorithm
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
    int n=6;
    int **adjMat=(int **)malloc(n*sizeof(int *));
    int i,j;
    for(i=0;i<n;i++){
        adjMat[i]=(int *)malloc(n*sizeof(int));
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            adjMat[i][j]=0;
        }
    }
    adjMat[0][1]=1;
    adjMat[0][2]=1;
    adjMat[1][3]=1;
    adjMat[2][3]=1;
    adjMat[3][4]=1;
    adjMat[3][5]=1;
    adjMat[4][5]=1;
    int *indegree=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        indegree[i]=0;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(adjMat[i][j]==1){
                indegree[j]++;
            }
        }
    }
    topologicalSort(adjMat,indegree,n);
    return 0;
}
// Time Complexity: O(V+E) where V is number of vertices in the graph and E is number of edges in the graph.