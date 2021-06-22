// double ended queue using (Doubly) Linked LIst

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node * f;
struct node * r;

//enq from rear
void enqueueR(int val){
    struct node * n = (struct node *) malloc(sizeof(struct node));
    if (n==NULL)
    {
        printf("Queue Full\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        n->prev = r;
        if (f==NULL) // if its the 1st node to be created
        {
            f=r=n;
            printf("Enqueued element from rear (special case/1st Node): %d\n", val);
        }
        else
        {
            r->next = n;
            r = n;
            printf("Enqueued element from rear: %d\n", val);
        }   
    }
}

//enqueue from front
void enqueueF(int val){
    struct node * n = (struct node *) malloc(sizeof(struct node));
    if (n==NULL)
    {
        printf("Queue Full\n");
    }
    else
    {
        n->data = val;
        n->next = f;
        n->prev = NULL;
        if (f==NULL) // if its the 1st node to be created
        {
            f=r=n;
            printf("Enqueued element from front (special case/1st Node): %d\n", val);
        }
        else
        {
            f = n; // inserted from front so, new f pointer is pointing to n(1st node now)
            printf("Enqueued element from front: %d\n", val);
        }   
    }
}

//dequeue from front
int dequeueF(){
    struct node * n = f;
    if (f==NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        f= f->next;
        f->prev = NULL;
        int val = n->data;
        free(n);
        return val;
    }   
}

//dequeue from rear
int dequeueR(){
    struct node * n = r; // pointer n , ppointing towards rearmost node
    if (f==NULL) // in empty both f and r are NULL
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        r = r->prev;
        r->next = NULL;
        int val = n->data; // data of rearmost node
        free(n);
        return val;
    }   
}

void display(struct node * ptr){
    printf("Linked List is :\n");
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr= ptr->next;
    }
    
}

int main()
{
    enqueueR(11);
    enqueueR(12);
    enqueueR(13);
    display(f);
    
    enqueueF(10);
    enqueueF(9);
    display(f);

    enqueueR(14);
    display(f);

    printf("Dequeued from front: %d\n", dequeueF());
    display(f);

    printf("Dequeued from rear: %d\n", dequeueR());
    display(f);

    return 0;
}