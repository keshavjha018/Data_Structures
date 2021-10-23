// recursive implementation of 01 knapsack

#include<stdio.h>

int max(int a, int b){
    if (a>b)
        return a;

    else
        return b;
}

int knapsack01(int wt[], int val[], int W, int n){
    //base case
    if (n==0 || W ==0)
        return 0;

    //choice diagram, recursive
    // NOW, (start checking from last item)
    // If weight of the nth item is more than Knapsack(bag) capacity
    // item can't be put in bag
    if (wt[n-1] > W)
        return knapsack01(wt,val,W, n-1);

    //if wt of item < capacity, then either we can include or leave (whichever gives max profit)
    else
    {
        return max((val[n-1] + knapsack01(wt,val,W-wt[n-1],n-1)), (knapsack01(wt, val,W, n-1)));
    }
    
    
}

int main()
{
    int val[] = {60,100,120};
    int wt[] = {10,20,30};
    int W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    int net_profit = knapsack01(wt,val, W, n);
    printf("Net Profit: %d ", net_profit);
    return 0;
}

// Time complexity = O(2^n)
// Space complexity = O(1)  - no extra data str has been used for storing values