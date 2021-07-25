#include <stdio.h>

void display(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int *arr, int n){
    int key, j;
    for (int i = 1; i < n; i++)  // for passes
    // starts with 1 bcz => 23 | 1,34,3,22,4  <= process starts from here
    {
        key = arr[i]; //temp variable
        j = i-1;

        // loop for each insertion/comparison to the left array
        while (arr[j] > key && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        // finally j = -1 , after end of while loop
        arr[j+1] = key;
    }
}

int main()
{
    int arr[] = {23,1,34,3,22,4};
    int n = 6; //size of arr
    display(arr,n); //before sort

    insertionSort(arr, n);
    display(arr,n); //  after sort
    return 0;
}