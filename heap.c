#include<stdio.h>
#include<stdlib.h>
void fail()
{
    printf("Operation Fail\n");
}
int parent(int i)
{
    return (i-1)/2;
}
int left(int i)
{
    return 2*i+1;
}
int right(int i)
{
    return 2*i+2;
}
void swap(int * a,int * b)
{
    int x=*a;
    *a=*b;
    *b=x;
}
void MinHeapify(int H[],int posn,int hs)
{
    int smallest=posn;
    if(left(posn)<=hs-1&&H[left(posn)]<H[posn])
        smallest=left(posn);
    if(right(posn)<=hs-1&&H[right(posn)]<H[smallest])
        smallest = right(posn);
    if(smallest==posn)
        return;
    else
        swap(&H[posn],&H[smallest]);
    MinHeapify(H,smallest,hs);
}

int FindMin(int H[],int heapsize)
{
    if(heapsize>=1)
    {
        return H[0];
    }
    else
    {
        return -1;
    }
}
void Siftup(int H[],int posn)
{
    while(posn>0&&H[posn]<=H[parent(posn)])
    {
        swap(&H[posn],&H[parent(posn)]);
        posn=parent(posn);
    }
}
int Insert(int H[],int hs,int x)
{
    hs++;
    H[hs-1]=x;
    Siftup(H,hs-1);
}
int DecreaseKey(int H[],int hs,int i,int value)
{
    if(H[i]<value)
        return -1;
    H[i]=value;
    Siftup(H,i);
}
int ExtractMin(int H[],int * hs)
{
    if(*hs==0)
    {
        return -1;
    }
    int temp=H[0];
    H[0]=H[*hs-1];
    *hs--;
    MinHeapify(H,0,*hs);
    return temp;
}
int delet(int H[],int *hs,int i)
{
    swap(&H[i],&H[*hs-1]);
    MinHeapify(H,i,*hs);
    *hs--;
}
void BuildHeap(int H[],int hs)
{
    int i=hs-1;
    while(hs>=0)
    {
        // if((right(i)>hs-1)&&(left(i)>hs-1))
        //     continue;
        MinHeapify(H,i,hs);
        hs--;
    }
    
}
void printheap(int H[],int hs)
{
    for(int i=0;i<hs;i++)
        printf("%d\n",H[i]);
}
int main()
{
    int x,n,H[100],var,var1,heapsize,c;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&H[i]);
    }

    BuildHeap(H,heapsize);

    heapsize=n;
    do
    {
        scanf("%d",&x);
        switch(x)
        {
            case 1 :
                 scanf("%d",&var);
                 var1=Insert(H,heapsize,var);
                 if(var1==-1)
                 {
                     fail();
                 }
                 break;

            case 2 :
                 scanf("%d",&var);
                 var1=delet(H,&heapsize,var);
                 break;
            case 3 :
                 var= ExtractMin(H,&heapsize);
                 if(var==-1)
                 {
                     fail();
                 }
                 else
                {
                    printf("%d\n",var);
                }
                 break;
            case 4 :
                 printheap(H,heapsize);
                 break;
            case 5 :
                 scanf("%d",&var);
                 scanf("%d",&var1);
                 c=DecreaseKey(H,heapsize,var,var1);
                 if(c==-1)
                 {
                     fail();
                 }
                 break;
            case 6 :
                 var=FindMin(H,heapsize);
                 if(var==-1)
                    fail();
                 else  
                    printf("%d\n",var); 
                break;


            default :
                 exit(0);
        }
    } while (1);
    
}