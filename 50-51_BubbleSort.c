#include <stdio.h>

void display(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubblesort(int *arr, int n){
    int temp;
    for (int i = 0; i < n-1; i++) // loop for passes
    {
        for (int j = 0; j < n-1-i ; j++) // for comparing elements
        {
            if (arr[j] > arr[j+1])
            {
                //swap
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]= temp;
            }
        }
    }
}

//  if the array gets sorted before all the passes
// we can save time by returning then and there without furthur passes
void bubblesortAdaptive(int *arr, int n){
    int temp;
    int isSorted = 0; // indicator of sorting
    for (int i = 0; i < n-1; i++) // loop for passes
    {
        printf("This is pass no. %d \n", i+1); // show pass number
        isSorted = 1; // if array does not enter the loop => it is sorted
        for (int j = 0; j < n-1-i ; j++) // for comparing elements
        {
            if (arr[j] > arr[j+1])
            {
                //swap
                isSorted =0; // array entered loop=> unsorted
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]= temp;
            }
        }
        if (isSorted)  // if sorted the stop passing and end
            return;
    }
}

int main()
{
    int arr[] = {23,1,34,3,22,4};
    int n = 6; //size of arr
    display(arr,n); // before sort

    bubblesortAdaptive(arr, n);
    display(arr,n); // after sort
    return 0;
}