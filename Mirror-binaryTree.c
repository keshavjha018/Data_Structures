//Write a program to convert a Binary tree into its Mirror Tree

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

//inorder traversal (left->root->right)
void inorder(struct node * root){
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void mirror(struct node *root){
    if (root == NULL)
    {
        return;
    }
    else
    {
        struct node *temp;
        mirror(root->right);
        mirror(root->left);

        temp = root->left;
        root->left = root->right;
        root->right = temp;
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
   
   printf("Prev Tree: ");
   inorder(p);

   mirror(p);

   printf("\nMirror Tree: ");
   inorder(p);
   
   return 0;
}