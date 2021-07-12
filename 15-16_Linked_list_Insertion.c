// video 15,16

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

//Insertion of new element at 1st position
struct Node * InsertatFirst(struct Node *head, int data)
{
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data= data;
    return ptr; // ptr is the new head
}

// insert at given index
struct Node * Insertatindex(struct Node * head, int data, int index)
{
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    int i =0;
    while(i != index-1)
    {
        p = p->next;
        i++;
    }
    
    ptr->next = p->next;
    p->next  = ptr;
    return head;
}

//insertion at end
struct Node * insertatEnd(struct Node* head, int data)
{
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node* p = head;
    
    while(p->next != NULL)
    {
        p = p->next;
    }

    ptr->next= NULL;
    p->next = ptr;
    return head;
}

//insertion after NODE
struct Node* insertafterNode(struct Node* head, struct Node* prevNode, int data)
{
    struct Node* ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
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

    printf("Before insertion:\n");
    printLinkedList(head); // before insertion

    //head = InsertatFirst(head, 55); // new head -- as inserted at 1st position
    //head = Insertatindex(head, 56, 2);
    head = insertafterNode(head, second, 99);

    printf("After insertion:\n");
    printLinkedList(head);
    return 0;
}