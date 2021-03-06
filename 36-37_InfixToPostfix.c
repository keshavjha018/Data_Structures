#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
    int top;
    int size;
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
// finding presudence
int preced(char a){
    // if (a =='(' || a== ')' || a=='{' || a=='}' || a=='[' || a==']')
    // {
    //     return 3;
    // }
    if (a =='/' || a== '*')
    {
        return 3;
    }
    else if (a =='+' || a== '-')
    {
        return 2;
    }
    else
        return 0;
}

int isOperator(char a){
    if (a =='+' || a== '-' || a=='*' || a=='/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
char pop(struct stack *ptr)  // to retuen char => char pop
{
    if (isEmpty(ptr))
    {
        printf("stack Underflow\n");
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

// returns precedence of stack top
int stackTop(struct stack * ptr){
    return ptr->arr[ptr->top];
}

char* intopo(char* infix){
    struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 30;
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    char * postfix = (char *) malloc(sizeof(char) * (strlen(infix)+1));
    int i=0, j=0; // infix and postfix counter/scanner

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i])) // not an operator
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if(preced(infix[i]) > preced(stackTop(sp)) )
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            } 
        }
    }
    // moving left out operators to postfix array
    while (!isEmpty(sp)) // is not empty
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';  // end of char array
    return postfix;
}
int main()
{
    char * infix = "x-y*d+2*a";
    printf("%s",intopo(infix));
    return 0;
}