#include<stdio.h>
void insert(int i,int *A)
{
    int cur_el=A[i];
    int j=i-1;
    while(A[j]>cur_el&&j>=0)
    {
        A[j+1]=A[j];
        j--;
    }
    A[j+1]=cur_el;   
}
void ins_sort(int n,int *A)
{
    int i=1;
    while(i<n)
    {
        insert(i,A);
        i++;
    }

}

int main()
{
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)

        scanf("%d",&A[i]);

    ins_sort(n,A);

    for(int i=0;i<n;i++)
        printf("%d\n",A[i]);
    
    return 0;
}
    
