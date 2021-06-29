// operations in binary search tree - 1. searching

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node * right;
};

struct node* createnode(int data){
    struct node* n = (struct node*) malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
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

//search function in binary search tree
struct node* search(struct node* root, int key){
    if (root == NULL) // if empty tree
    {
        return NULL;
    }
    else if (root->data == key) // if root itself is the number to find
    {
        return root;
    }
    else if (key < root->data) // if key is less than root (data)
    {
        return search(root->left, key); // search in left subtree
    }
    else if (key > root->data) // if key is greater than root (data)
    {
        return search(root->right, key); // search in righ subtree
    }
    
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

    inorder(p);

    struct node* n = search(p,11);
    if (n != NULL)
    {
        printf("\nnumber found ! %d\n", n->data);
    }
    else
    {
        printf("\nNot found the given number\n");
    }
    
    return 0;

}

   