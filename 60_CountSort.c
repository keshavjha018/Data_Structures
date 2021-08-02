#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

void display(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int maximum(int A[], int n){
    //finding max ele
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (A[i]>max)
        {
            max = A[i];
        }
    }
    return max;
}

void countSort(int A[], int n)
{
    // Find the maximum element in A
    int max = maximum(A,n);

    // creating temp array to store frequency
    int* temparray = (int *) malloc((max+1) * sizeof(int));

    // initializing all ele with 0
    for (int j = 0; j < max+1 ; j++)
    {
        temparray[j] = 0;
    }

    // incrementing all acc to frequency
    for (int k = 0; k < n; k++)
    {
        temparray[A[k]] = temparray[A[k]] + 1;
    }

    //wherever the freq is not 0, we copy those indices (frequenct no of times) in array
    int i=0; // counter for temp array
    int j=0; // counter for main array
    while (i<max+1)
    {
        if (temparray[i] > 0)
        {
            A[j] = i;
            // after placing, decrease the freq by 1
            temparray[i] = temparray[i] - 1 ;
            j++;
        }
        //if temparray element = 0 , =>> move on
        else
        {
            i++;
        }
    }
}

int main()
{
    int A[] = {23,1,34,3,22,4};
    int n = 6; //size of arr
    display(A,n); //before sort
    //printf("MAX = %d\n", maximum(A,n));

    countSort(A, n);
    display(A,n); //  after sort
    return 0;
}