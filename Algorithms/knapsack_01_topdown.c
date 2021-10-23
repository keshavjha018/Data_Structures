// top down approach
#include<stdio.h>

int max(int a, int b){
    if (a>b)
        return a;
    else
        return b;
}

int knapsack_td(int wt[],int val[],int W, int n){
    int t[n+1][W+1];

    //Iteration
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < W+1; j++)
        {
            // base condition
            if (i==0 || j==0)
                t[i][j] = 0;

            // if item can fit in knapsack
            else if (wt[i-1] <= j)
                t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]] , t[i-1][j]);

            // if item cant fit
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][W];
}

int main()
{
    int val[] = {60,100,120};
    int wt[] = {10,20,30};
    int W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    int net_profit = knapsack_td(wt,val, W, n);
    printf("Net Profit: %d ", net_profit);
    return 0;
}