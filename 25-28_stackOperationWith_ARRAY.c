// tutorial 25,26,27,28
//stack operations using array - push, pop, peek

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int check(struct stack * ptr) //fn to check whether stack is empty/full
{
    if (ptr->top == -1)
    {
        //stack empty
        return -1;
    }
    else if (ptr->top == (ptr->size) - 1)
    {
        // stack full
        return 1;
    }
    else
    {
        //neither empty nor full
        return 0;
    }
}

//push fn
void push(struct stack *ptr , int value)
{
    if (check(ptr) == 1)
    {
        printf("Stack Overflow, cant push %d\n", value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int main()
{
    struct stack *s;
    s->size = 10;
    s->top = -1;
    s->arr = (int *) malloc(s->size * sizeof(int));

    printf("Before Push: %d \n", check(s));
    push(s, 34);
    push(s, 54);
    push(s, 35);
    push(s, 64);
    printf("After Push: %d \n", check(s));
    return 0;
}