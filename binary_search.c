#include<stdio.h>
int depth;
int bin_search(int *A,int left,int right,int item)
{
    depth ++;
    int mid=0,position=0;
    if(left==right)
    {
        if(A[left]==item)
        {
            return left;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        mid=(left+right)/2;
        if(A[mid]==item)
        {
            position=mid;
        }
        else if((item<A[mid])&&(left<mid))
        {
            position=bin_search(A,left,mid-1,item);
        }
        else if((item>A[mid])&&(mid<right))
        {
            position=bin_search(A,mid+1,right,item);
        }
        else
        {
            position =-1;
        }
        return position;
    }

}
int main()
{
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    int location=0;
    int x;
    scanf("%d",&x);
    depth=0;
    location=bin_search(A,0,n,x);
    printf("%d\n%d",depth,location);
    return 0;
}