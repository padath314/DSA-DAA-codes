#include<stdio.h>
void select(int n,int A[])
{
    int max=0,ind=0;
    for(int i=0;i<n;i++)
    {
        if(max<A[i])
        {
            max=A[i];
            ind=i;
        }
    }
    int t=A[n-1];
    A[n-1]=max;
    A[ind]=t;

}
void sel_sort(int n,int A[])
{
    for(int i=0;i<n;i++)
    {
        select(n-i,A);
    }
}

void insert(int n, int A[])
{
    int x=A[n];
    int j=n-1;

    while(j>=0&&x<A[j])
    {
        A[j+1]=A[j];
        j--;
    }
    A[j+1]=x;
}

void ins_sort(int n,int A[])
{
    for(int i=0;i<n;i++)
    {
        insert(i,A);
    }
}
int pp(int pivot,int first,int last,int A[])
{
    int rank=first;
    int p;
    for(int i=first;i<last+1;i++)
    {
        if(A[i]==pivot)
        {
            p=i;
        }
        if(A[i]<pivot)
        {
            rank++;
        }
    }
    A[p]=A[rank];
    A[rank+first]=pivot;

    int i=first;
    int j=rank+1;
    while(i<rank && j<last+1)
    {
        while(i<rank && A[i]<pivot)
        {
            i++;
        }
        while(j<last+1 && A[j]>pivot)
        {
            j++;
        }
        while(i<rank&&j<last+1)
        {
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i++;
            j++;
        }
    }
    return rank+first;
}

// void quicksort(int A[],int a,int n)
// {
//     pp()
// }


void merge(int f, int l,int A[])
{
    int mid=(f+l)/2;
    int i=f,j=mid+1;
    int k=0;
    int arr[l-f+1];
    while(i<=mid && j<=l)
    {
        if(A[i]<=A[j])
        {
            arr[k]=A[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=A[j];
            j++;
            k++;
        }
    }
        while(j<=l)
        {
            arr[k]=A[j];
            j++;
            k++;
        }
        while(i<=mid)
        {
            arr[k]=A[i];
            i++;
            k++;
        }
        
    for(int k=f;k<=l;k++)
    {
        A[k]=arr[k-f];
    }

}

// void mer_sort(int A[],int first,int last)
// {
    
// }



int main()
{
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    ins_sort(n,A);
    for(int i=0;i<n;i++)
    {
        printf("%d\n",A[i]);
    }
    return 0;

}