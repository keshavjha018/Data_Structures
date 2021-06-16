#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

//function for printing list elements
void printLinkedList(struct Node *ptr) // takes head pointer as input
{
    while (ptr != NULL)
    {
        printf("element: %d \n", ptr->data); // prints data of that pointer
        ptr = ptr->next;  // points ptr to next node 
    }
    
}

//check Empty
int isEmpty(struct Node *top){
    // if the top pointer is pointing to NULL => stack is empty
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//check Full
int isFull(struct Node *top){
    struct Node *n = (struct Node *) malloc(sizeof(struct Node));
    // it is linked list so it cant be full easily as we increase size with each step (unlike array)
    // even then, if we are not able to allocate memory dynamically, we can say that memory is full
    if (n == NULL) // means n is not allocated => insufficient memory => stack FULL
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
    struct Node * top = (struct Node *) malloc(sizeof(struct Node));
    top->data = 23232;
    top->next = NULL;

    printLinkedList(top);
    return 0;
}