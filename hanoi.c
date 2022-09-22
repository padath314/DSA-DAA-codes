#include<stdio.h>
void tow(int n,int t1,int t3,int t2)
{
    if(n==1)
    {
        printf("Move disk %d from Pole %d to Pole %d\n",n,t1,t3);
    }
    else if(n>1)
    {
        tow(n-1,t1,t2,t3);
        printf("Move disk %d from Pole %d to Pole %d\n",n,t1,t3);
        tow(n-1,t2,t3,t1);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    tow(n,0,2,1);
    return 0;
}