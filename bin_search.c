#include<stdio.h>
int binsearch(int A[],int x,int left,int right)
{
    int position=0,mid=0;
    if(left==right)
    {
        if(A[left]==x)
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
        int mid=(left+right)/2;
        if(A[mid]==x)
        {
            position=mid;
        }
        else if(x<A[mid] && mid>left)
        {
            position=binsearch(A,x,left,mid-1);
        }
        else if(x>A[mid] && mid<right)
        {
            position=binsearch(A,x,mid+1,right);
        }
        else
        position=-1;
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
    int x;
    scanf("%d",&x);
    int y=binsearch(A,0,n-1,x);
    printf("%d",y);
    return 0;

}