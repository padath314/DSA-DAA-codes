#include<stdio.h>
#include<stdlib.h>
struct node
{
    int item;
    struct node * next;
}* temp;

struct data
{
    int entry;
    int exit;
    int visited;
    int pred;
    int completed;
};

int clock;

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

void DfsExplore(int v1,struct data * G[],struct node * A[])
{
    G[v1]->visited=1;
    G[v1]->entry=clock;
    clock++;
    int c=0;

    struct node * temp=A[v1]->next;
    while(temp!=NULL)
    {
        c++;
        int x=temp->item;
        if(G[x]->visited==0)
        {
            G[x]->pred=v1;
            DfsExplore(x,G,A);
        }
        temp=temp->next;
    }
    G[v1]->exit=clock;
    clock++;
    
}

void DfsExplore_nonrec(int v1,struct data * G[],struct node * A[])
{
    int curr = v1;
    G[curr]->visited=1;
    while(!(curr == v1 && G[curr]->completed))
    {
        if(!G[curr]->visited)
        {
            struct node* neigh = A[curr]->next;
            G[curr]->completed = 1;
            while(neigh != NULL)
            {
                if(!(G[neigh->item]->visited))
                {
                    G[curr]->completed = 0;
                }
                neigh =  neigh->next;
            }
            
        }
    }
}

void DepthFirstExpl(int v1,struct data * G[],struct node * A[],int n)
{
    clock=0;
    DfsExplore(v1,G,A);
    for(int i=0;i<n;i++)
    {
        if(G[i]->visited==0)
        {
            DfsExplore(i,G,A);
        }
    }
}


void printdata(int n,struct data * G[])
{
    for(int i=0;i<n;i++)
    {
        printf("%d %d\n",G[i]->entry,G[i]->exit);
    }
}

int main()
{
    int n,m,ind1,ind2;
    struct node * abc;
    scanf("%d",&n);
     struct node* A[n];
    scanf("%d",&m);
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

    int startingvertex;
    scanf("%d",&startingvertex);
    struct data * G[n];
    for(int i=0;i<n;i++)
    {
        G[i]=malloc(sizeof(struct data));
        if(G[i]==NULL)
        {
            exit(1);
        }
        G[i]->visited=0;
        G[i]->entry=-1;
        G[i]->exit=-1;
        G[i]->pred=-1;
        G[i]->completed=0;

    }
    DepthFirstExpl(startingvertex,G,A,n);

    printdata(n,G);
    return 0;
}