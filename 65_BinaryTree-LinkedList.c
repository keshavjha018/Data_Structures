#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

// function for creating nodes
struct node * createnode(int val){
    struct node *n = (struct node*) malloc(sizeof(struct node));
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int main()
{
    // creating nodes using function
    struct node *p = createnode(2);
    struct node *p1 = createnode(1);
    struct node *p2 = createnode(4);

    // linking
    p->left = p1;
    p->right = p2;

    /*
    creating nodes separately, without functions

    //creating root node
    struct node* p = (struct node*) malloc(sizeof(struct node));
    p->data = 2;
    p->left = NULL;  
    p->right = NULL;

    // creating 2nd node
    struct node* p1 = (struct node*) malloc(sizeof(struct node));
    p1->data = 1;  
    p1->left = NULL;  
    p1->right = NULL;  

    // creating 3rd node
    struct node* p2 = (struct node*) malloc(sizeof(struct node));
    p2->data = 4;  
    p2->left = NULL;  
    p2->right = NULL;

    //linking nodes for binary tree
    p->left = p1;
    p->right = p2;
    */

    return 0;
}