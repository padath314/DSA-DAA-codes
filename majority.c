#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }

    int freq=0,cur=-1;
    for(int i=0;i<n;i++)
    {
        if(freq==0)
        {
            cur=A[i];
            freq=1;
        }
        else if(A[i]==cur)
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]==cur)
        {
            count++;
        }
    }
    if(count>n/2)
    {
        printf("%d",cur);
    }
    else
    {
        printf("No Majority");
    }

    return 0;
    }