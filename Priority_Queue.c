//Write a program to implement a priority queue
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    int pr;
    struct node *next;
};

// front and rear pointers
struct node *f;
struct node *r;

int max;
struct node *maxprnode;

void insert(int data, int pr){
    struct node *ptr = (struct node *) malloc(sizeof(struct node));
    if (ptr==NULL) // if memory not allocated
    {
        printf("Overflow\n");
    }
    else if (f==NULL && r==NULL) // empty queue
    {
        ptr->data = data;
        ptr->pr = pr;
        ptr->next = NULL;
        f=r=ptr;
        printf("Enqueued %d\n", data);

        // setting max priority
        max = pr;
        maxprnode = ptr;
    }
    else
    {
        ptr->data = data;
        ptr->pr = pr;
        ptr->next = NULL;
        r->next = ptr; // linking r>next with ptr
        r=ptr; // ptr is the new rear
        printf("Enqueued %d\n", data);

        // setting max priority
        if (pr > max)
        {
            max = pr;
            maxprnode = ptr;
        }
    }
}

void display(){
    if (f==NULL)
    {
        printf("Empty Queue\n");
    }
    else
    {
        struct node *temp = f;
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp!=NULL);   
    }
}

void delete_highest_priority(){
    if (r==NULL)
    {
        printf("Empty\n");
    }
    else
    {
        struct node *temp = f;

        if (f == r) // if only 1 node is present in queue(so f=r)
        {
            free(r);
        }
        else if (temp->pr == max) // else if 1st node is first priority node
        {
            f = f->next ;
            free(temp);
        }
        
        else
        {
            while (temp->next->pr != max)
            {
                temp=temp->next;
            }
            // now temp points to previous of max priority node
            temp->next = maxprnode->next ;
            free(maxprnode);
        }
    }
    
}

int main()
{
    insert(11,6);
    insert(22,7);
    insert(13,2);
    insert(3,7);
    insert(54,5);

    printf("The Queue is: ");
    display();

    printf("\nMaximum priority data is: %d\n", maxprnode->data);

    delete_highest_priority();
    printf("Queue after deleting Max priority is:\n");
    display();

    return 0;
}