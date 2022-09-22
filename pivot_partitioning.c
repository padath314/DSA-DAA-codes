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
   int k;
   scanf("%d",&k);
   int pivot=A[k];
   int r=0;
   for(int i=0;i<n;i++)
   {
       if(A[i]<pivot)
       {
           r++;
       }
   }
   A[k]=A[r];
   A[r]=pivot;

  for(int i=0,j=r+1;i<r,j<n;)
  {
      if(A[i]<A[r])
      {
          i++;
      }
      else if(A[j]>=A[r])
      {
          j++;
      }
      else
      {
          int t=A[i];
          A[i]=A[j];
          A[j]=t;
          i++;
          j++;
        
      }
  }

  for(int i=0;i<n;i++)
  {
      printf("%d\n",A[i]);
  }
  return 0;

}