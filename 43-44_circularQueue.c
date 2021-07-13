#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct circularQueue{
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(struct circularQueue *ptr){
    if (ptr->f == ptr->r)
    {
        return 1;
    }
    return 0;
}

int isFull(struct circularQueue *ptr){
    if ((ptr->r  + 1)% ptr->size == ptr->f)
    {
        return 1;
    }
    return 0;
}

void display(struct circularQueue *q){
    if (q->r == q->f)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int i = q->f;
        do
        {
            printf("%d ", q->arr[i+1]);
            i = (i+1) % q->size ;
        } while (i != q->r);   
    }   
}

void enqueue(struct circularQueue *ptr, int val){
    if (isFull(ptr))
    {
        printf("Queue is Full\n");
    }
    else
    {
        //circular increment => will go to 0th position after last 
        ptr->r = (ptr->r + 1) % ptr->size; 
        ptr->arr[ptr->r] = val;
        printf("Enqueued element: %d\n", val);
    }
    
}

int dequeue(struct circularQueue *ptr){
    if (isEmpty(ptr))
    {
        printf("Queue is empty\n");
        return 0;
    }
    else
    {
        ptr->f = (ptr->f + 1) % ptr->size;
        int a = ptr->arr[ptr->f];
        return a;
    }
    
}

int main()
{
    struct circularQueue * q1 = (struct circularQueue *) malloc(sizeof(struct circularQueue));
    q1->size = 4;
    q1->f = 0; // in circular  f & r start with 0, for circular increment to work.
    q1->r = 0;
    q1->arr = (int *) malloc(q1->size * sizeof(int));

    enqueue(q1, 23);
    enqueue(q1, 2);
    enqueue(q1, 32);

    printf("Dequeuing element %d\n", dequeue(q1));
    printf("Dequeuing element %d\n", dequeue(q1));
    printf("Dequeuing element %d\n", dequeue(q1));

    if (isEmpty(q1))
    {
        printf("Queue is Empty\n");
    }
    else if (isFull(q1))
    {
        printf("Queue is Full\n");
    }
    
    printf("\nProblem solved now:\n");
    enqueue(q1, 33);
    enqueue(q1, 35);
    enqueue(q1, 54);

    if (isEmpty(q1))
    {
        printf("Queue is Empty\n");
    }
    else if (isFull(q1))
    {
        printf("Queue is Full\n");
    }
    return 0;
}