#include<stdio.h>
#include<stdlib.h>
struct node
{
    int key;
    struct node * next;
}* ptr,*prev,* head;

void insert(struct node * p)
{
    int x= (p)->key;
    ptr=head;
    if(ptr->key>x)
    {
        head=(p);
        (p)->next=ptr;
    }
    else
    {
        while(ptr->next!=NULL && ptr->key<=x)
        {
            prev=ptr;
            ptr=ptr->next;
        }
        if(ptr->next==NULL&&ptr->key<x)
        {
            (p)->next=NULL;
            ptr->next=(p);
        }
        else
        {
            prev->next=(p);
            (p)->next=ptr;
        }
    }
}

int main()
{
  
    int x;
   
    for(int i=0;i<5;i++)
    {
        scanf("%d",&x);
        ptr=malloc(sizeof(struct node));
        if(ptr==NULL)
        {
            exit(0);
        }
        ptr->key=x;
        ptr->next=NULL;
        if(i==0)
        {
            head=ptr;
        }
        else
        {        
        insert(ptr);
        }
    }

    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->key);
        ptr=ptr->next;
    }
    return 0;
}