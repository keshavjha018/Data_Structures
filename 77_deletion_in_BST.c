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

//returns inorder predecessor
struct node *inorderpred(struct node *root){
    root = root->left;
    while (root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}

struct node *delete(struct node *root, int value){
    if (root==NULL)
    {
        return NULL;
    }
    //if root is leaf node
    else if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    // search for the node to be deleted
    else if (value > root->data)
    {
        root->right = delete(root->right, value);
    }
    else if (value<root->data)
    {
        root->left = delete(root->left, value);
    }
    // deletion, node is found
    // value == root->data
    else
    {
        struct node *ipre = inorderpred(root); // inorder predcessor
        root->data=ipre->data;  // replacing the node to be deleted with its inorder pred(we can)
        root->left = delete(root->left, ipre->data); // deleting data of ipre
        // >> as already stored at the place of prev node (which we wanted to delete)
    }
    return root;
}

int main()
{
    struct node *p = createnode(5);
    struct node *p1 = createnode(3);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(1);
    struct node *p4 = createnode(4);

    //linking
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

/*
             5
           /   \ 
          3     6
        /  \      
       1    4      
*/

    inorder(p);

    delete(p,5);
    printf("\n After Deletion\n");
    inorder(p);

    return 0;
}