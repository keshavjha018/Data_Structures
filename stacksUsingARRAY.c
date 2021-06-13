#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *array;
};

// fun to check if stack is empty/full
int check(struct stack * ptr)
{
    if (ptr->top == -1)
    {
        //stack is empty
        return -1;
    }
    else if (ptr->top== 79)
    {
        //stack is full
        return 1;
    }
    
    
}
int main()
{
    struct stack s1;
    s1.size = 80; //let
    s1.top = -1; // empty so pointing before 0
    s1.array = (int *) malloc((s1.size)*sizeof(int));

    // stacks using pointer
    struct stack *s2;
    s2->size = 80;
    s2-> top = -1;
    s2->array = (int *) malloc((s2->size)*sizeof(int));

    if (check(s2)== -1)
    {
        printf("Stack is empty! \n");
    }
    else if (check(s2)== 79)
    {
        printf("stack is FULL! \n");
    }
    

    return 0;
}