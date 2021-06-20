#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queue{
    int size;
    int f;  //front index counter
    int r; // read index co.
    int *arr;
};

int isEmpty(struct queue * ptr){
    if (ptr->r == ptr->r)
    {
        return 1; // is empty
    }
    return 0;
}

int isFull(struct queue * ptr){
    if (ptr->r == ptr->size - 1)
    {
        return 1; // queue full
    }
    return 0;
}

void enqueue(struct queue * ptr, int val){
    if (isFull(ptr))
    {
        printf("Queue is Full\n");
    }
    else
    {
        ptr->r++;
        ptr->arr[ptr->r] = val;
    }
}

int dequeue(struct queue * ptr){
    // int a = -1; // just for reference = no need
    if (isEmpty(ptr))
    {
        return 0;
    }
    else
    {
        ptr->f++;
        int a = ptr->arr[ptr->f];

        // if both f & r are pointing to same location of array
        // we can start with -1 again to save memory (tutorial 42)
        if (ptr->f == ptr->r)
        {
            ptr->f = ptr->r = -1;
        }
        
        return a;
    }
    
}

void peek(struct queue *ptr, int index){
    printf("%d\n", ptr->arr[index + ptr->f]);
}

int main()
{
    struct queue * q1 = (struct queue *) malloc(sizeof(struct queue));
    q1->size = 20;
    q1->f = -1;
    q1->r = -1;
    q1->arr = (int *) malloc(q1->size * sizeof(int));

    enqueue(q1, 23);
    enqueue(q1, 2);
    peek(q1, 1);
    peek(q1, 2);

    dequeue(q1);
    dequeue(q1);
    if (isEmpty(q1))
    {
        printf("Queue is Empty\n");
    }
    return 0;
}