#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node *f = NULL;
struct node *r = NULL;
// using global values, as we are making
// changes to the value (tutorial 46, 9:00:00)

struct node
{
    int data;
    struct node *next;
};

void enqueue(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n==NULL)
    {
        printf("queue Full\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        //special case when f & r both pointers are NULL,
        // i.e. there are no nodes in LL initially
        if (f==NULL)
        {
            f = r = n;
            printf("Enqueued element (special case/1st Node): %d\n", val);
        }
        else
        {
            r->next = n;
            r = n;
            printf("Enqueued element: %d\n", val);
        }
    }
}

int dequeue()
{
    struct node *ptr = f;
    if (f==NULL)
    {
        printf("Queue is empty!\n");
        return 0;
    }
    else
    {
        f = f->next;
        int val = ptr->data;
        free(ptr);
        return val;
    }
}

void display(struct node *ptr){
    //takes front pointer as arg
    printf("Linked List: \n");
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr=ptr->next;
    }  
}

int main()
{
    printf("Dequeued element: %d\n", dequeue());
    enqueue(10);
    enqueue(11);
    enqueue(12);
    display(f);
    printf("Dequeued element: %d\n", dequeue());
    display(f);
    return 0;
}