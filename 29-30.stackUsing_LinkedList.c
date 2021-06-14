// 29 - 30
// Implementation of stacks using linked list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

void printLinkedList(struct Node *ptr) // takes head pointer as input
{
    while (ptr != NULL)
    {
        printf("element: %d \n", ptr->data); // prints data of that pointer
        ptr = ptr->next;  // points ptr to next node 
    }
    
}

//push operation
int push(struct Node *head, int value)
{
    struct Node *new = (struct Node*) malloc(sizeof(struct Node));
    new->data = value;
    new->next = head;
    //head = new;
    return new;
}


int main()
{
    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    struct Node *second = (struct Node*) malloc(sizeof(struct Node));
    struct Node *third = (struct Node*) malloc(sizeof(struct Node));
    
    head->data = 11;
    head->next = second;

    second->data = 12;
    second->next = third;

    third->data = 13;
    third->next = NULL;

    printLinkedList(head);
    printf("\nAfter PUSH\n\n");
    head = push(head,14);
    printLinkedList(head);

    return 0;
}