#include <stdio.h>
// K E S H A V
//function for max heap
// n = size of array, i = root
void max_heapify(int arr[],int n,int i){
    int L = 2*i + 1; //left nodes for root = i
    int R = 2*i + 2;  //right nodes
    int largest = i; // initially largest node = root

    //if any left child  > largest node , before leaf node
    if (arr[L] > arr[largest] && L<n)
    {
        largest = L;
    }
    //same for right
    if (arr[R] > arr[largest] && R<n)
    {
        largest = R;
    }
    //if largest is not at root
    if (largest != i)
    {
        //swap
        int temp;
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        //again max heapify the affected subtree (affected due to swap)
        max_heapify(arr,n,largest);
    }
    
}

void heapsort(int arr[], int n){
    // range of internal nodes => n/2 - 1 to 0
    for (int i = n/2 -1; i >= 0; i--)
    {
        //make the heap => max heap
        max_heapify(arr,n,i);
    }
    //extract elements from heap to array
    for (int i = n-1; i >= 0 ; i--)
    // i-- bcz =>> we are reducing size of heap after each iteration,
    // as we need to delete /ignore last element which is to be swapped
    {
        // Move current root to end
        //swap
        int temp;
        temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;

        //rearrange the reduced heap ie. make the heap => max heap
        max_heapify(arr,i,0);
    }
    
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ",arr[i]);
}

int main()
{
    int arr[5] = {2,3,1,4,6};
    int n = 5;
    printArray(arr,n);

    heapsort(arr,n);
    printf("\nAfter Heap Sort: \n");
    printArray(arr,n);

    return 0;
}