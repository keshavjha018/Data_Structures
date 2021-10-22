#include <stdio.h>

// merge sort
void merge(float A[] , int mid, int low, int high){
    float B[high+1];
    int i = low, j = mid+1, k = low;
    while (i <= mid && j <= high)
    {
        if (A[i] >= A[j])  // both >= and > works, decide later
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

void mergesort(float A[], int low, int high){
    int mid;
    if (low<high) // no of elements >=2
    {
        mid = (low+high)/2 ;
        mergesort(A, low, mid); // run same fun for all the portions of array
        mergesort(A, mid+1, high);
        merge(A, mid, low, high); // merge all sorted array  
    }  
}

//fun to find index of element using vw ratio
int indexx(float ratio, float unsorted_vw[], int n){
    for(int j =0;j<n;j++){
        if(unsorted_vw[j]==ratio){
            return j;
        }
    }
}

float fr_knapsack(int n, float value[], float wt[], float capacity){
    float vw[n];
    //calculating v/w ratio
    for(int i=0; i<n ; i++){
        vw[i] = value[i]/wt[i];
    }

    float unsorted_vw[n];
    for(int i =0;i<n;i++){
        unsorted_vw[i] = vw[i];
    }

    // sorting vw ratio in decreasing order
    mergesort(vw,0,n-1);

    float empty_wt = capacity, profit = 0; // initially bag is empty

    for(int i=0; i<n;i++){
        // vw[i] is ele with max vw ratio,
        //so indexx fun returns the index of that item in original list
        int ind = indexx(vw[i], unsorted_vw,n);
        if(empty_wt>0 && wt[ind]<= empty_wt){
            empty_wt = empty_wt - wt[ind];
            profit = profit + value[ind];
        }
        //after we cant fit the item as whole in bag, we take their fraction
        else{
            if(empty_wt > 0){
                profit = profit + value[i]*empty_wt/wt[i];
            }
            break;
        }
    }

    return profit;
}

int main()
{
    float value[] = {50,60,70,70};
    float wt[] = {10,20,30,40};
    float capacity = 60;
    int n = sizeof(value)/sizeof(float);
    float net_profit = fr_knapsack(n, value, wt, capacity);
    printf("Net Profit: %f ", net_profit);
    return 0;
}