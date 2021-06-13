#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int A[35]={1,2,3,4,5,6};
    int B[45]={1,2,5,6};

    for (int i = 0; i < 35; i++)
    {
        for (int j = 0; j < 45; j++)
        {
            if (A[i]==B[j])
            {
                printf("%d ", A[i]);
            }
            else
            {
                return 0;
            }
            
               
        }
    }
    
    return 0;
}