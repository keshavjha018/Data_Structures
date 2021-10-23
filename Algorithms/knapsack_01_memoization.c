// implementation of 01 knapsack - memoization Approach
#include<stdio.h>
#include <string.h>

//matrix to store already calculated recursive solutions
int t[12][102];

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

    // if value is already stored in matrix
    if (t[n][W] != -1)
        return t[n][W];

    // If weight of the nth item is more than Knapsack(bag) capacity
    // item can't be put in bag
    if (wt[n-1] > W)
        return t[n][W] = knapsack01(wt,val,W, n-1); // return and set value in the matrix

    //if wt of item < capacity, then either we can include or leave (whichever gives max profit)
    else
    {
        // return and set value in the matrix
        return t[n][W] = max((val[n-1] + knapsack01(wt,val,W-wt[n-1],n-1)), (knapsack01(wt, val,W, n-1)));
    }
}

int main()
{
    int val[] = {60,100,120};
    int wt[] = {10,20,30};
    int W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    memset(t,-1,sizeof(t));
    int net_profit = knapsack01(wt,val, W, n);
    printf("Net Profit: %d ", net_profit);
    return 0;
}

/**
 Time complexity = O(n*W)
**/