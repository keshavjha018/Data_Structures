#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;          
    struct Node *next; 
};

//function for printing list elements
void printLinkedList(struct Node * head) 
{
    struct Node * ptr = head;
    do
    {
        printf("element: %d \n", ptr->data); 
        ptr = ptr->next;
    } while (ptr != head);
       
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));

    // storing elements and linking
    head->data = 221; 
    head->next = second; 

    second->data = 24;
    second->next = third;

    third->data = 51;
    third->next = head;

    //calling print fn
    printLinkedList(head);
    return 0;
}