#include <stdio.h>
#include <stdlib.h>

// Creating data type for linked list
// as we have to store two values here - 1- Element , 2- Address of next node
struct Node
{
    int data;          // stores element
    struct Node *next; // stores address of next node
};

//function for printing list elements
void printLinkedList(struct Node *ptr) // takes head pointer as input
{
    while (ptr != NULL)
    {
        printf("element: %d \n", ptr->data); // prints data of that pointer
        ptr = ptr->next;  // points ptr to next node 
    }
    
}

int main()
{
    // creating pointer variables
    /* LIke---
        int *ptr
    */
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // allocating memory dynamically (from heap)
    /*  after     int *ptr 
    LIke---
        ptr = (int *) malloc(3*sizeof(int)) ==>> Size required
    */
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));

    // storing elements and linking
    head->data = 221; // 1st element
    head->next = second; // linking firest node with 2nd node

    second->data = 24;
    second->next = third;

    third->data = 51;
    third->next = NULL;  // assigning last node (ie 3rd) node as NULL

    //calling print fn
    printLinkedList(head); // sending head pointer as a function arg
    return 0;
}