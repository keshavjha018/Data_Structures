// to check if any subset from a given set makes a given sum or not

#include <stdio.h>

int SumofSubset(int set[], int sum, int n){

    // sum left == 0 => subset found
    if (sum == 0)
        return 1; // true
        
    // sum left != 0 and no element left furthur, => not found
    if (sum > 0 && n == 0)
        return 0; // false

    // If last element is greater than sum, then ignore it
    if (set[n - 1] > sum)
         return SumofSubset(set, sum, n - 1);

    // either include or exclude
    return SumofSubset(set, sum - set[n-1], n-1) || SumofSubset(set, sum, n-1);
}

int main()
{
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    if (SumofSubset(set, n, sum) == 1)
        printf("Found subset");
    else
        printf("No subset");
    return 0;
}