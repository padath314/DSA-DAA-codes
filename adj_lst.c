#include<stdio.h>
#include<stdlib.h>
struct node
{
    int item;
    struct node * next;
}* temp;
struct node * makenode(int i,int x,struct node* A[])
{
    struct node * ptr= malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        return ptr;
    }
    ptr->item=x;
    ptr->next=NULL;
    temp=A[i];
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=ptr;
    return ptr;
}

void printadjacencylist(int n,struct node * A[])
{
    for(int i=0;i<n;i++)
    {
        int c=0;
        temp=A[i]->next;
        
        while(temp!=NULL)
        {
            c++;
            printf("%d",temp->item);
            if(temp->next!=NULL)
                printf(" ");
            temp=temp->next;
        }
        if(c==0)
        {
            printf("Nil");
        }
        printf("\n");

    }
}
int main()
{
    int n,m,ind1,ind2;
    struct node * abc;
    scanf("%d",&n);
    scanf("%d",&m);
    struct node* A[n];
    for(int k=0;k<n;k++)
    {
        A[k]=malloc(sizeof(struct node));
        if(A[k]==NULL)
        {
            exit(1);
        }
        A[k]->item=k;
        A[k]->next=NULL;
    }
    for(int k=0;k<m;k++)
    {
        scanf("%d",&ind1);
        scanf("%d",&ind2);
        abc=makenode(ind1,ind2,A);
        if(abc==NULL)
        {
            exit(1);
        }
        abc=makenode(ind2,ind1,A);
        if(abc==NULL)
        {
            exit(1);
        }
    }

    printadjacencylist(n,A);
    return 0;
}