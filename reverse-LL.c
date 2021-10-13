#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data;
    struct node *next;
};

struct node *insert(struct node *head,int data){

    struct node *n = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr=ptr->next;
    }
    //  ptr is the last node now
    
    n->data = data;
    n->next = NULL;
    ptr->next = n;
    return head;
}

void display(struct node *head){
    struct node *ptr = head;
    while (ptr!= NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    
}

struct node *reverseLL(struct node *head){

    struct node *prev = NULL;
    struct node *current = head;
    struct node  *next = NULL;

    while (current != NULL)
    {
        // Store next
        next = current->next;
        
        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
    return head;

    // struct node *p = head;
    // struct node *q = head->next;
    // struct node *r;
    // while (q != NULL)
    // {  
    //     r=q->next;
    //     q->next = p;

    //     if (r==NULL) // last condition
    //     {
    //         head=q ;
    //         return head;
    //     } 
        
    //     p=q;
    //     q=r;
    // }
    // return head;
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 11;
    head->next = NULL;

    head = insert(head, 22);
    head = insert(head, 33);
    head = insert(head, 44);
    head = insert(head, 55);
    display(head);

    printf("\n");
    head = reverseLL(head);
    display(head);
    return 0;
}