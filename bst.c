#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;

    struct node *left;

    struct node *right;

} node;

void free_tree (node *root);

void print_tree (node *root);

int main (void)
{
    node *tree = NULL;

    //sample root node

    node *n = malloc(sizeof(node));

    if (n == NULL)
    {
        free_tree(tree);

        return 1;
    }

    n->num = 2;

    n->left = NULL; n->right = NULL;

    tree = n;

    //sample left child

    n = malloc(sizeof(node));

    if (n == NULL)
    {
        free_tree(tree);

        return 1;
    }

    n->num = 1;

    n->left = NULL; n->right = NULL;

    tree->left = n;

    //sample right node
    
    n = malloc(sizeof(node));

    if (n == NULL)
    {
        free_tree(tree);

        return 1;
    }

    n->num = 3;

    n->left = NULL; n->right = NULL;

    tree->right = n;

    //printing the tree

    print_tree(tree);

    //freeing allocated memory

    free_tree(tree);
}

void print_tree(node *root)
{
    if (root = NULL)
    {
        return;
    }

    print_tree(root->left);

    printf("%i ", root->num);

    print_tree(root->right);
}

void free_tree (node *root)
{
    if (root == NULL)
    {
        return;
    }

    free_tree(root->left);

    free_tree(root->right);

    free_tree(root);
}