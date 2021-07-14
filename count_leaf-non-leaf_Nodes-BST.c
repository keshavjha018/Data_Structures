// Write a program to count the number of leaf and non-leaf nodes
// in a binary search tree.

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node * right;
};

int total=0;
int leafnode=0;

struct node* createnode(int data){
    struct node* n = (struct node*) malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    total++ ;
    return n;
}

void inorder(struct node * root){
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// fun to count leaf nodes
int countleaf(struct node *root){
    if (root!= NULL && root->right == NULL && root->left == NULL)
    {
        leafnode++ ;
        return leafnode;
    }
    countleaf(root->left);
    countleaf(root->right);

    return leafnode;   
}

int main()
{
    struct node* p = createnode(5);
    struct node* p1 = createnode(3);
    struct node* p2 = createnode(6);
    struct node* p3 = createnode(1);
    struct node* p4 = createnode(4);

    //linking
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("Inorder BST : ");
    inorder(p);
    printf("\nTotal no of nodes is: %d\n", total);

    // LEAF NODE
    int leafN = countleaf(p);
    printf("Total LEAF nodes is: %d\n", leafN);

    // FOR NON-LEAF NODES
    int nonleaf = total - leafN ;
    printf("Total NON-LEAF nodes is: %d\n", nonleaf);
    

    return 0;
}