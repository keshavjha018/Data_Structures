// to check if the given expression has proper parenthesis pair or not
// by stacks using array
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr){
    if (ptr->top == -1)
    {
        return 1;       
    }
    else
    {
        return 0;
    }
    
}

void push(struct stack *ptr, char value)
{
    if (ptr->top == ptr->size - 1)
    {
        printf("stack overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

void pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("stack Underflow\n");
    }
    else
    {
        ptr->top--;
    }
}

int parenthmatch(char *exp)  // will take char type input
{
    //create a stack
    struct stack *sp;
    sp->size = 25;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp)) // if empty
            {
                return 0;
            }
            pop(sp); // else
        }
    }
    if (isEmpty(sp)) // if stack is finally empty => parenthesis Match
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *exp = "3+(4-32)(";

    if (parenthmatch(exp))
    {
        printf("Parenthesis Matched !\n");
    }
    else
    {
        printf("Parenthesis NOT Matched !\n");
    }
    return 0;
}