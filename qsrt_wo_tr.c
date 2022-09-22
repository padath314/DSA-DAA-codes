#include<stdio.h>

int partition(int *A,int left, int right, int p)
{
  int r=left;
  int pivot=A[p];
  for(int k=left;k<=right;k++)
  {
    if(pivot>A[k])
      r++;
  }
  
  A[p]=A[r];
  A[r]=pivot;

  int i=left;
  int j=r+1;
  while(i<r && j<right+1)
  {
      while(i<r&&A[i]<pivot)
      {
        i++;
      }
      while(j<right+1&&A[j]>=pivot)
      {
        j++;
      }
      if(i<r && j<right+1)
      {
          int temp=A[i];
        A[i]=A[j];
        A[j]=temp;
       i++;
       j++;
      }
  }

  return r;
}

void quicksort(int *A,int first,int last)
{
    if(first==last)
        return;
    int pivot=A[first];
    int pivot_rank=partition(A,first,last,first);
    if(pivot_rank>first)
    {
      quicksort(A,first,pivot_rank-1);
    }
    if(pivot_rank<last)
    {
     quicksort(A,pivot_rank+1,last);
    }

}

int main()
{
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)

        scanf("%d",&A[i]);
    quicksort(A,0,n-1);
    for(int i=0;i<n;i++)
      printf("%d\n",A[i]);
    return 0;

}