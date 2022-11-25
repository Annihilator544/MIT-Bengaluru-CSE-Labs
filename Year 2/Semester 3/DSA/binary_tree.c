#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
struct node *create_node(int);
struct node *delete (struct node *, int);
struct node *smallest_node(struct node *);
struct node *largest_node(struct node *);
int get_data();

int main()
{
    int userChoice;
    int userActive = 'Y';
    int data;
    struct node* result = NULL;
        printf("1. Insert");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n4. Larger Data");
        printf("\n5. smaller data");
        printf("\n6. Inorder ");
        printf("\n7. Post Order ");
        printf("\n8. Pre Oder ");
        printf("\n9. Exit");
    userChoice=0;
    while (userChoice!=9)
    {
        printf("\nEnter Your Choice: ");
        scanf("%d", &userChoice);
        switch(userChoice)
        {
            case 1:
                data = get_data();
                insert(data);
                break;

            case 2:
                data = get_data();
                root = delete(root, data);
                break;

            case 3:
                data = get_data();
                if (search(data) == 1)
                {
                    printf("\nData was found!\n");
                }
                else
                {
                    printf("\nData not found!\n");
                }
                break;

            case 4:
                result = largest_node(root);
                if (result != NULL)
                {
                    printf("\nLargest Data: %d\n", result->data);
                }
                break;

            case 5:
                result = smallest_node(root);
                if (result != NULL)
                {
                    printf("\nSmallest Data: %d\n", result->data);
                }
                break;

            case 6:
                inorder(root);
                break;

            case 7:
                postorder(root);
                break;

            case 8:
                preorder(root);
                break;

            case 9:
                printf("\nProgram was terminated\n");
                break;

            default:
                printf("Invalid Choice\n");
                break;
        }
    }

    return 0;
}
struct node *create_node(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("\nMemory for new node can't be allocated");
        return NULL;
    }

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}
void insert(int data)
{
    struct node *new_node = create_node(data);

    if (new_node != NULL)
    {
        if (root == NULL)
        {
            root = new_node;
            printf("%d was inserted\n", data);
            return;
        }

        struct node *temp = root;
        struct node *prev = NULL;
        while (temp != NULL)
        {
            prev = temp;
            if (data > temp->data)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
        if (data > prev->data)
        {
            prev->right = new_node;
        }
        else
        {
            prev->left = new_node;
        }

        printf("%d was inserted\n", data);
    }
}
struct node *delete (struct node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root->data)
    {
        root->left = delete (root->left, key);
    }
    else if (key > root->data)
    {
        root->right = delete (root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = smallest_node(root->right);
        root->data = temp->data;
        root->right = delete (root->right, temp->data);
    }
    return root;

}
int search(int key)
{
    struct node *temp = root;

    while (temp != NULL)
    {
        if (key == temp->data)
        {
            return 1;
        }
        else if (key > temp->data)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    return 0;
}
struct node *smallest_node(struct node *root)
{
    struct node *curr = root;
    while (curr != NULL && curr->left != NULL)
   {
        curr = curr->left;
    }
    return curr;
}
struct node *largest_node(struct node *root)
{
    struct node *curr = root;
    while (curr != NULL && curr->right != NULL)
    {
        curr = curr->right;
    }
    return curr;
}
void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",  root->data);
    inorder(root->right);
}
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
int get_data()
{
    int data;
    printf("\nEnter Data: ");
    scanf("%d", &data);
    return data;
}
