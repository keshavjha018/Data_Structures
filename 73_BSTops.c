// operations in binary search tree - 1. searching (Recursive), 2. Iterative search 3. Max/min value
//4. Insertion in BST

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

//search function (Recursive) in binary search tree
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

//recursive search function
struct node* ItrSearch(struct node * root, int key){
    while (root!=NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key > root->data)
        {
            root = root->right; // search in right subtree
        }
        else // key < root->data >> search in left subtree
        {
            root = root->left;
        }
    }
    return NULL; //if root = NULL >> it will not enter the while loop
}

// Function to find the node with maximum value
int maxValue(struct node *node) 
{
    struct node *current = node;
    int max = current->data; 
    while (current != NULL)
    {
        if (current->data > max)
        {
            max = current->data;
        }
        current = current->right;
    }
    return max;
}

// Function to find the node with minimum value
int minValue(struct node *node) 
{
    struct node *current = node;
    int min = current->data ;
    while (current != NULL)
    {
        if (current->data < min)
        {
            min = current->data;
        }
        current = current->left;
    }
    return min;
}

void insert(struct node *root, int key){
    struct node *prev = NULL; // pointer which will traverse, and find the location/node for insertion
    while(root != NULL) // finding location/node
    {
        prev = root;
        if (key == root->data)
        {
            printf("Cant insert %d , Already in BST\n",key);
            return;
        }
        else if (key>root->data)
        {
            root=root->right;
        }
        else
        {
            root=root->left;
        }
    }
    // now, prev pointer holds the location/node where we can insert the given no
    //creating new node & storing data(to be inserted)
    struct node* new = createnode(key);
    // inserting
    if (key>prev->data)
    {
        prev->right=new;
    }
    else
    {
        prev->left=new;
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

    /*
                 5
               /   \ 
              3     6
            /  \      \
           1    4      7
    */

    inorder(p);

    struct node* n = ItrSearch(p,1);
    if (n != NULL)
    {
        printf("\nnumber found >> %d\n", n->data);
    }
    else
    {
        printf("\nNot found the given number\n");
    }
    
    insert(p, 7);
    printf("new element: %d\n",p->right->right->data);
    inorder(p);
    printf("\n");

    // delete(p,3);
    // inorder(p);

    return 0;

}

   