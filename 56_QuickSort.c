#include <stdio.h>

void display(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// places 1st element(pivot) in array in such a way that
// elements smaller than it are on left and larger ele are on its right
int partition(int A[], int low, int high){
    int i,j,temp, pivot;
    // let 1st element is pivot
    pivot = A[low];
    i = low + 1;
    j = high;
    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }
        if (i<j)
        {
            //swap A[i] and A[j]
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
        
    } while (i<j);
    //swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high){
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(A,low,high);

        // run same fun for left and right part of the array
        quickSort(A, low, partitionIndex-1);
        quickSort(A, partitionIndex+1, high);
    }
}

int main()
{
    int A[] = {23,1,34,3,22,4};
    int n = 6; //size of arr
    display(A,n); //before sort

    quickSort(A, 0, n-1);
    display(A,n); //  after sort
    return 0;
}