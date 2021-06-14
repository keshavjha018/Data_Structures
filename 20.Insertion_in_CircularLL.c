// video - 20

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

//function for printing list elements
void printLinkedList(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("element: %d \n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

// insertion at head in circular Linked list
struct Node * InsertionAtHead(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // storing elements and linking
    head->data = 221;
    head->next = second;

    second->data = 24;
    second->next = third;

    third->data = 51;
    third->next = head;

    printf("Before insertion\n");
    printLinkedList(head);

    head = InsertionAtHead(head, 80);

    printf("After insertion\n");
    printLinkedList(head);
    return 0;
}