// video 21

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

//printing / traversal
void printlistfromSTART(struct Node *head) // printing from start
{
    struct Node *ptr = head;
    do
    {
        printf("Element: %d \n", ptr->data);
        ptr = ptr->next;
    } while (ptr != NULL);
}

void printlistfromEND(struct Node *end) // printing from end
{
    struct Node *ptr = end;
    do
    {
        printf("Element: %d \n", ptr->data);
        ptr = ptr->prev;
    } while (ptr != NULL);
}

int main()
{
    //creating nodes
    struct Node *N1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *N2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *N3 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *N4 = (struct Node *)malloc(sizeof(struct Node));

    // storing data
    N1->data = 11;
    N2->data = 12;
    N3->data = 13;
    N4->data = 14;

    //linking
    N1->prev = NULL;
    N1->next = N2;

    N2->prev = N1;
    N2->next = N3;

    N3->prev = N2;
    N3->next = N4;

    N4->prev = N3;
    N4->next = NULL;

    printf("Doubly Linked List from start\n");
    printlistfromSTART(N1);
    printf("Doubly Linked List from the end\n");
    printlistfromEND(N4);
    return 0;
}