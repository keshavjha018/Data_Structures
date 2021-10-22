#include <stdio.h>

void display(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// fun to merge two given arrays
void merge(int A[] , int mid, int low, int high){
    int B[high+1];
    int i = low, j = mid+1, k = low;
    while (i <= mid && j <= high)
    {
        if (A[i] >= A[j])  // both >= and > works => decide later
        {
            B[k] = A[i];
            k++;
            i++;
        }
        else
        {
            B[k] = A[j];
            k++;
            j++;
        }
    }
    // if any of the array finished,
    // then copy the remaining one as it is, as they are already sorted
    while (i<=mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j<=high)
    {
        B[k] = A[j];
        k++;
        j++;
    }

    // finally moving all ele of B to A
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergesort(int A[], int low, int high){
    int mid;
    if (low<high) // no of elements >=2
    {
        mid = (low+high)/2 ;
        mergesort(A, low, mid); // run same fun for all the portions of array
        mergesort(A, mid+1, high);
        merge(A, mid, low, high); // merge all sorted array  
    }  
}

int main()
{
    int arr[] = {23,1,34,3,22,4,3};
    //int arr[] = {9,14,4,8,7,5,6};
    int n = 7; //size of arr
    display(arr,n); // before sort

    mergesort(arr,0,6);
    display(arr,n); // after sort
    return 0;
}