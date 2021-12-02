// to check if any subset from a given set makes a given sum or not

#include <stdio.h>
#include <stdbool.h>

bool SumofSubset(int set[], int sum, int n){

    bool DP[n+1][sum + 1];
    
    // if sum is 0 => ans true -> subset found
    for (int i = 0; i <= sum; i++)
        DP[i][0] = true;
    
    // no of ele = 0 , sum isnt 0 => false
    for (int i = 1; i <= sum; i++)
        DP[0][i] = false;
    

    // Fill the subset table in bottom up manner
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            // if sum < ele => ignore
            if (j < set[i - 1])
                DP[i][j] = DP[i - 1][j];
            // sum >= set ele
            if (j >= set[i - 1])
            // either or
                DP[i][j] = DP[i - 1][j] || DP[i - 1][j - set[i - 1]];
        }
        
    }
    
    return DP[n][sum];
}

int main()
{
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 14;
    int n = sizeof(set) / sizeof(set[0]);
    if (SumofSubset(set, n, sum) == true)
        printf("Found subset");
    else{
        printf("No subset");
    }
        
    return 0;
}