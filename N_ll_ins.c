#include<stdio.h>
#include<stdlib.h>
struct node                     
{
    int item;
    struct node * next;
};
struct node * first;

void insert(struct node * nptr)
{
    struct node * cur_ptr,* prev_ptr=NULL;
    int x= nptr->item;
    cur_ptr=first;
    if(cur_ptr->item>x)
    {
        first=nptr;
        nptr->next=cur_ptr;
        return;
    }
   else
   {
        while(cur_ptr->next!=NULL&&cur_ptr->item<=x)
        {
           
            prev_ptr=cur_ptr;
            cur_ptr=cur_ptr->next;
        }
   
    if(cur_ptr->next==NULL&&cur_ptr->item<x)               
        {
            nptr->next=NULL;
            cur_ptr->next=nptr;
        }
        else
        {
            prev_ptr->next=nptr;
            nptr->next=cur_ptr;
        }
   }
}


int main()
{
    int n,x;
    struct node * newptr,* cur_ptr;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        newptr=(struct node *)malloc(sizeof(struct node));
        if (newptr!=NULL)
        {
            scanf("%d",&x);
            newptr->item=x;
            newptr->next=NULL;
            if(i==0)
            {
                first=newptr;
                cur_ptr=first;
            }
            else
            {
                insert(newptr);
            }
            
        }
        
    }

    cur_ptr=first;

     while(cur_ptr!=NULL)
    {
        printf("%d\n",cur_ptr->item);
        cur_ptr=cur_ptr->next;
    }

    return 0;

}