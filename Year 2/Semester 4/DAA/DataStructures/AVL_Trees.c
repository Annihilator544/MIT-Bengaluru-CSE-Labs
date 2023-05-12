//Avl trees algorithm
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};
int max(int a,int b){
    return a>b?a:b;
}
int height(struct Node *root){
    if(root==NULL){
        return 0;
    }
    return root->height;
}
struct Node *createNode(int data){
    struct Node *n=(struct Node *)malloc(sizeof(struct Node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    n->height=1;
    return n;
}
struct Node *rightRotate(struct Node *y){
    struct Node *x=y->left;
    struct Node *t2=x->right;
    //perform rotation
    x->right=y;
    y->left=t2;
    //update heights
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    //return new root
    return x;
}
struct Node *leftRotate(struct Node *x){
    struct Node *y=x->right;
    struct Node *t2=y->left;
    //perform rotation
    y->left=x;
    x->right=t2;
    //update heights
    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;
    //return new root
    return y;
}
int getBalance(struct Node *root){
    if(root==NULL){
        return 0;
    }
    return height(root->left)-height(root->right);
}
struct Node *insert(struct Node *root,int data){
    if(root==NULL){
        return createNode(data);
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }
    else if(data>root->data){
        root->right=insert(root->right,data);
    }
    else{
        return root;
    }
    root->height=1+max(height(root->left),height(root->right));
    int balance=getBalance(root);
    //left left case
    if(balance>1 && data<root->left->data){
        return rightRotate(root);
    }
    //right right case
    if(balance<-1 && data>root->right->data){
        return leftRotate(root);
    }
    //left right case
    if(balance>1 && data>root->left->data){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    //right left case
    if(balance<-1 && data<root->right->data){
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
void preorder(struct Node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main(){
    struct Node *root=NULL;
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,30);
    root=insert(root,25);
    root=insert(root,28);
    root=insert(root,27);
    root=insert(root,5);
    root=insert(root,15);
    root=insert(root,19);
    root=insert(root,16);
    preorder(root);
    return 0;
}
