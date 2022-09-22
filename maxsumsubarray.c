#include<stdio.h>
int main()
{
    int n,k;
    scanf("%d %d",&n, &k);

    int A[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }

    int max = 0;
    int wsum = 0,wstart = 0;
    for(int wend = 0; wend < n;wend++)
    {
        wsum += A[wend];
        if(wend >= k-1)
        {
            if(wsum > max)
            {
                max = wsum;
            }
        
        
        wsum -= A[wstart];
        wstart ++;
        }
        
    }

    printf("%d", max);
    

}