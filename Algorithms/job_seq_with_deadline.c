#include <stdio.h>
#include <stdbool.h>

//merge sort
void merge(int A[], int mid, int low, int high){
    int B[high+1];
    int i = low, j = mid+1, k = low;
    while (i<=mid && j <= high)
    {
        if (A[i] >= A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    // if any of the array gets empty, copy as it is (already sorted)
    while (i<=mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j<=high)
    {
        B[k] = A[j];
        j++;
        k++;
    }
    // moving all ele of B to A
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergesort(int A[], int low , int high){
    int mid = (low+high)/2;
    if (low<high)
    {
        mergesort(A,low, mid);
        mergesort(A, mid+1, high);
        merge(A, mid, low, high);
    }
    
}

//returns index from the original order of joobs (before sorting)
int indexx(int arr[], int pro , int n ){
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == pro)
            return i;
    }
    
}

int min(int a, int b){
    if(a<b)
        return a;
    else
        return b;
}

void job_seq(int profit[], int deadline[], int n){
    
    // temp array to store original seq
    int unsorted[n];
    for (int i = 0; i < n; i++)
    {
        unsorted[i] = profit[i];
    }

    //sorting by profit
    mergesort(profit,0,n-1);

    int result[n]; // store result (index order)
    bool slot[n]; // check slot is free or not
    //initialise all slot as free & result as -1
    for (int i = 0; i < n; i++){
        slot[i] = false;
        result[i] = -1;
    }

    // iterate
    for (int i = 0; i < n; i++)
    {
        int in = indexx(unsorted, profit[i], n);
        for (int j = min(n, deadline[in]) - 1; j>= 0; j--)
        {
            if (slot[j] == false)
            {
                result[j] = indexx(unsorted, profit[i], n) + 1; //add this job to result
                slot[j] = true; // slot occupied
                break;
            }
        }
    }
    //printing results
    printf("The max profit seq. of jobs is :\n");
    for (int i = 0; i < n; i++)
    {
        if (result[i] != -1)
        {
            printf("%d  ",result[i]);
        }
    }
    
}

int main()
{
    int profit[] = {60,100,20,40,20};
    int deadline[] = {2,1,3,2,1};
    int n = sizeof(profit)/sizeof(profit[0]);

    printf("Sequence of jobs for maximum profit: \n");
    job_seq(profit,deadline,n);
    
    return 0;
}