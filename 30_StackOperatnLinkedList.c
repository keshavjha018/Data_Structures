#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node * top = NULL; // GLOBAL Variable // top is pointer of struct Node type which is initially pointing to NULL
// made global as, we will do changes in its values, which can only be done if its a global variable


//function for printing list elements
void printLinkedList(struct Node *ptr) 
{
    while (ptr != NULL)
    {
        printf("Element: %d \n", ptr->data);
        ptr = ptr->next;
    }
    
}

// PUSH
//will return top (of type struct Node) so, define fun of struct Node type
// struct Node* push(struct Node * top, int value)
// {
//     struct Node * n = (struct Node *) malloc(sizeof(struct Node)); // making a new node
//     if (n==NULL)
//     {
//         printf("Stack Overflow\n");
//     }
//     else
//     {
//         n->data = value;
//         n->next = top; // linked the new node with 1st node, where top pointer was pointing to
//         top = n;  // now top pointer is pointing to new node n
//         return top;
//     }
// }

void push(int value){
    struct Node * n = (struct Node *) malloc(sizeof(struct Node)); // making a new node
    if (n==NULL)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        n->data = value;
        n->next = top; // linked the new node with 1st node, where top pointer was pointing to
        top = n;  // now top pointer is pointing to new node n
    }
}

//POP
void pop(){
    struct Node * temp;
    if (top == NULL)
    {
        printf("Stack IS EMPTY\n");
    }
    else
    {
        temp = top;
        printf("Popped Element is %d\n", top->data);
        top = top->next;
        free(temp);
    } 
}
// ------HARRY'S CODE--------

// int pop(struct Node *top)
// {
//     if (top == NULL) // if top pointer is pointing to NULL
//     {
//         printf("Stack UnderFlow\n");
//     }
//     else
//     {
//         struct Node *n = top; //n is new temp pointer to store value of top
//         topP = top->next; // now topP will point to next node (ie top->next)
//         int value = n->data;
//         free(n);
//         return value;
//     }
// }

int main()
{
    // ----HARRY's CODE----

    // top = push(top, 23);
    // top = push(top, 43);
    // top = push(top, 24);
    
// ========= GFG code ========
    push(23);
    push(43);
    push(24);
    printLinkedList(top);

    printf("After POP\n");
    pop(top);
    printLinkedList(top);
    return 0;
}
