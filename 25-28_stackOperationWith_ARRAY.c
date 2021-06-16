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

//fn to check whether stack is empty or full
int check(struct stack *ptr)
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
void push(struct stack *ptr, int value)
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

// pop fn - pops the topmost element
int pop(struct stack *ptr)
{
    if (check(ptr) == -1)
    {
        printf("Stack Underflow (empty), cant pop\n");
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

// peek fn
int peek(struct stack *ptr, int i)
{
    int arrindex = ptr->top - i + 1;
    if (arrindex < 0)
    {
        printf("Invalid Position\n");
        return -11;
    }
    else
    {
        return ptr->arr[arrindex];
    }
}

int main()
{
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // PUSH
    printf("Before Push: %d \n", check(s));
    push(s, 34);
    push(s, 5);
    push(s, 335);
    push(s, 54);
    push(s, 1);
    push(s, 114);
    push(s, 164);
    push(s, 41);
    push(s, 614);
    push(s, 4);
    push(s, 6); // -->> 11th push => stack overflow

    printf("After Push: %d \n", check(s));

    // POP last(topmost) element of stack =>> 10th push i.e 4
    // last in -->> first Out
    printf("Popped %d from the stack\n", pop(s));

    //PEEK
    //printing stack elements(of given index) using Peek
    for (int j = 1; j <= s->top + 1; j++)
    {
        printf("Element at index %d : %d\n", j, peek(s, j));
    }

    return 0;
}