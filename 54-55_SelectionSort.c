#include <stdio.h>

void display(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int n){
    printf("Running selection sort...\n");
    int frontIndex, min, minindex;
    int temp;
    for (int i = 0; i < n-1 ; i++)
    {
        minindex=i;
        min = arr[minindex];
        // finding min from this new index
        for (int j = i+1 ; j < n ; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                minindex = j;
            }
        }
        // swapping =>> swap(arr[i], arr[minindex]);
        temp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = temp;
    }
}

int main()
{
    int arr[] = {23,1,34,3,22,4};
    int n = 6; //size of arr
    display(arr,n); //before sort

    selectionSort(arr, n);
    display(arr,n); //  after sort
    return 0;
}