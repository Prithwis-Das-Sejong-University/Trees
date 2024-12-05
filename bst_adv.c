#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;

    struct node *left;

    struct node *right;

} node;

node *createnode (int data)
{
    node *newnode = malloc(sizeof(node));
    
    newnode->data = data;

    newnode->left = NULL; newnode->right = NULL;

    return newnode;
}

node *insertnode (node *root, int data)
{
    if (root == NULL)
    {
        root = createnode(data);
    }

    else if (data < root->data)
    {
        root->left = insertnode(root->left, data);
    }

    else 
    {
        root->right = insertnode(root->right, data);
    }

    return root;
}

node *findmin (node *root)
{
    while (root->left != NULL)
    {
        root  = root->left;
    }

    return root;
}

node *findmax (node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }

    return root;
}

node *deletenode (node *root, int data)
{
    if (root = NULL)
    {
        return root;
    }

    if (data < root->data)
    {
        root->left = deletenode(root->left, data);   
    }

    else if (data > root->data)
    {
        root->right = deletenode(root->right, data);
    }

    else
    {
        // node with only one child or no child

        if (root->left == NULL)
        {
            node *temp = root->right;

            free(root);

            return temp;
        }

        else if (root->right == NULL)
        {
            node *temp = root->left;

            free(root);

            return temp;
        }

        // node with 2 children: in order successor or in order predecessor

        node *temp = findmin(root->right);

        root->data = temp->data;

        root->right = deletenode(root->right, temp->data);

        // in-order successor
        
        //node *temp = findmax(root->left);

        //root->data = temp->data;

        //root->left = deletenode(root->left, temp->data);

    }

    return root;    
}

void preordertraversal (node *root)
{
    if (root != NULL)
    {
        printf("%i ", root->data);

        preordertraversal(root->left);

        preordertraversal(root->right);
    }
}

void postordertraversal (node *root)
{
    if (root != NULL)
    {
        postordertraversal(root->left);

        postordertraversal(root->right);

        printf("%i ", root->data);
    }
}

void inordertraversal (node *root)
{
    if (root != NULL)
    {
        inordertraversal(root->left);

        printf("%i ", root->data);

        inordertraversal(root->right);
    }
}

int main (void)
{
    node *root = NULL;

    root = insertnode(root, 50);

    insertnode(root, 30);
    insertnode(root, 70);
    insertnode(root, 20);
    insertnode(root, 40);
    insertnode(root, 60);
    insertnode(root, 80);

    printf("In-order traversal: ");

    inordertraversal(root);    
    
    printf("\n");

    return 0;
}




//in-order: 15,25,28,30,35,40,45,50,55,60,70

//pre-order: 40,30,25,15,28,35,50,45,60,55,70

//post-order: 15,28,25,35,30,45,55,70,60,50,40