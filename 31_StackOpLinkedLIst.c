#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node* top;

struct Node{
    int data;
    struct Node * next;
};

void printLL(struct Node * ptr){
    while (ptr!=NULL)
    {
        printf("Element: %d \n", ptr->data);
        ptr=ptr->next;
    }
}

void push(int val){
    struct Node* n = (struct Node*) malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Stack OVERFLOW\n");
    }
    else
    {
        n->data = val;
        n->next = top;
        top = n;
    } 
}

void pop(){
    struct Node *temp = top;
    if (top==NULL)
    {
        printf("Stack Underflow");
    }
    else
    {
        printf("Popped Element is %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

void peek(int position){
    struct Node * temp = top;
    for (int i = 0; i < position-1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp != NULL)
    {
        printf("%d rd Element is : %d\n",position,temp->data);
    }
    else
    {
        printf("Invalid Index\n");
    }
}

int main()
{
    push(12);
    push(53);
    push(314);
    push(234);
    push(4);
    push(3);
    printLL(top);

    printf("After POP\n");
    pop();
    printLL(top);

    peek(3);
    peek(4);
    return 0;
}