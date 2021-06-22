#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queue{
    int size;
    int f;  //front index counter
    int r; // rear index co.
    int *arr;
};

int isEmpty(struct queue * ptr){
    if (ptr->r == ptr->f)
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
        printf("Enqeued element: %d\n", val);
    }
}

int dequeue(struct queue * ptr){
    // int a = -1; // just for reference = no need
    if (isEmpty(ptr))
    {
        printf("Queue is Empty\n");
        return 0;
    }
    else
    {
        ptr->f++;
        int a = ptr->arr[ptr->f];

        // // if both f & r are pointing to same location of array
        // // we can start with -1 again to save memory (tutorial 42)
        // if (ptr->f == ptr->r)
        // {
        //     ptr->f = ptr->r = -1;
        // }
        
        return a;
    }
    
}

void display(struct queue *ptr)
{
    if (ptr->r == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue from end is: \n");
        for (int i = ptr->r; i > ptr->f; i--)
        {
            printf("%d ", ptr->arr[i]);
        }
        printf("\n");
    }
}

void count(struct queue *ptr)
{
    int count = 0;
    for (int i = ptr->r; i > ptr->f; i--)
    {
        count++;
    }
    printf("Total no of elements: %d\n", count);
}

// peek means viewing topmost element
void peek(struct queue *ptr){
    printf("Peeked Element: %d\n", ptr->arr[ptr->r]);
}

int main()
{
    struct queue * q1 = (struct queue *) malloc(sizeof(struct queue));
    q1->size = 4;
    q1->f = -1;
    q1->r = -1;
    q1->arr = (int *) malloc(q1->size * sizeof(int));

    enqueue(q1, 23);
    enqueue(q1, 2);
    enqueue(q1, 32);

    display(q1);

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
    
    // here we can observe that even  after dequeuing each element (ie queuw is made empty)
    // still we cant enqueue elements furthur (it will show "queue Full")
    //Because::==>
    // as our front and rear pointer(index) moves to end of array and cant be furthur used
    // t#is is the disadvantage of using linear queue
    printf("\nProblem begins now:\n");
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