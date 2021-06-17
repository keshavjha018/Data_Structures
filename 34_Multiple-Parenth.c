#include <stdio.h>
#include <stdlib.h>
//using stack - ARRAY
struct stack
{
    int top;
    int size;
    char *arr;
};

void push(struct stack *ptr, char val)
{
    if (ptr->top == ptr->size - 1)
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
    if (ptr->top == -1)
    {
        printf("stack Underflow\n");
    }
    else
    {
        char poppedChar = ptr->arr[ptr->top];
        ptr->top--;
        return poppedChar;
    }
}

//char cant be compared openly like int
int match(char a, char b){
    if (a== '(' && b== ')')
    {
        return 1;
    }
    else if (a== '{' && b== '}')
    {
        return 1;
    }
    else if (a== '[' && b== ']')
    {
        return 1;
    }
    return 0;
    
}

int MultParenthMatch(char *exp)
{ // will take char type input as arg
    // created a stack
    struct stack *sp;
    sp->top = -1;
    sp->size = 25;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char poppedCh;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (sp->top == -1)
            {
                return 0;
            }
            poppedCh = pop(sp);
            if (!match(poppedCh, exp[i])) // if popped char != prev pushed char
            {
                return 0;
            }
        }
    }
    if (sp->top == -1) //empty at end
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
    char *exp = "[4-6]((8){(9-8)}";
    if (MultParenthMatch(exp))
    {
        printf("Parenthesis BALENCED\n");
    }
    else
    {
        printf("Parenthesis NOT Balenced\n");
    }

    return 0;
}