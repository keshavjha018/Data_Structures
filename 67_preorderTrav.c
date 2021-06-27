#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

//fn for creating node
struct node* createnode(int val){
    struct node* n = (struct node *) malloc(sizeof(struct node));
    n->data= val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// preorder traversal
void preorder(struct node* root){
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
    
}

int main()
{
   struct node * p = createnode(7); 
   struct node * p1 = createnode(2); 
   struct node * p2 = createnode(3); 
   struct node * p3 = createnode(1); 
   struct node * p4 = createnode(4); 
   struct node * p5 = createnode(5);

   //linking
   p->left=p1;
   p->right = p2;
   p1->left = p3;
   p1->right = p4;
   p2->left = p5;

   preorder(p);
    return 0;
}