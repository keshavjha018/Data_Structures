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

// fun to check if tree is Binary search tree or not
//working via inorder traverssal || if inorder trav in ascending => BST
int isBST(struct node* root){
    static struct node* prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0; // if left subtree is not a BST => tree is not BST
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0; // if root (new) <= prev (root) >>>> not in ascending order >> not BST
        }
        prev = root; // prev updated (temporary prev pointer)
        return isBST(root->right); // same fn runs for right subtree
    }
    else
    {
        return 1; // empty tree => BST
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

    if (isBST(p))
    {
        printf("\n It is Binary Search Tree\n");
    }
    else
    {
        printf("\n It is NOT Binary Search Tree\n");
    }
    
    

    return 0;
}