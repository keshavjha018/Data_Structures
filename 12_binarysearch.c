#include <stdio.h>
int binarysearch(int arr[], int size, int element)
{
    int low = 0, mid;
    int high = size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid; // elememnt to be found is mid
        }
        else if (arr[mid] > element)
        {
            high = mid - 1; //new high is mid-1 becz element at mid (ie arr[mid]) has already been checked,
                            // and element is not found there.
        }
        else if (arr[mid] < element)
        {
            low = mid - 1;
        }
    }
}
void main()
{
    int arr[] = {2, 3, 8, 44, 45, 55, 99, 204, 223, 532};
    int size = sizeof(arr) / sizeof(int);
    int element = 45; // element to find
    //calling binary search function
    int index = binarysearch(arr, size, element);
    printf("The given number is found at index %d", index);
}