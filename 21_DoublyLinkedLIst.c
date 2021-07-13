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

// struct node *head; or N1; should be made global for using these functions
// and remove head as argument from insert function
//insertion
void insert(struct Node* head, int data){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    if (head == NULL)
    {
        ptr->data = data;
        ptr->prev = NULL;
        ptr->next = NULL;
        head = ptr;
    }
    else
    {
        struct Node *temp = head;
        // finding last node >> to insert
        while (temp->next != NULL)
        {
            temp=temp->next;
        }

        temp->next = ptr;
        ptr->data = data;
        ptr->prev = temp;
        ptr->next= NULL;
        
    }
}

//deleting a given value
void delete(struct Node *head, int value){
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p= p->next;
        q=q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    
    
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