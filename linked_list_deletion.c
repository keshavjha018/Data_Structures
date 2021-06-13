#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printLinkedList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("element: %d \n", ptr->data);
        ptr = ptr->next;
    }
}

//deleting 1st node
struct Node *DeletefirstNode(struct Node *head)
{
    struct Node *ptr = head; // new pointer variable pointing towards head
    head = head->next;
    free(ptr);
    return head;
}

// deletion of node at given index
struct Node *DeleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;

    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }

    p->next = q->next;
    free(q);
    return head;
}

//deleting last node
struct Node *DeletingLastNode(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

//delete node of given value (firtst)
struct Node *DeleteNodeofGivenValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->data != value && q->next != NULL) // it may be possible that the given value is not in the list
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
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
    third->next = NULL;

    printf("Before deletion:\n");
    printLinkedList(head); // before deletion

    printf("After Deletion\n");
    head = DeleteNodeofGivenValue(head, 24);
    printLinkedList(head); // after deletion
    return 0;
}