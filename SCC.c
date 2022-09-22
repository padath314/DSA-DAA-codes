#include <stdio.h>
#include <stdlib.h>

struct node
{
    int item;
    struct node *next;
    struct node *end;
} * temp, *temp1,*topo;

struct data
{
    int vertexno;
    int entry;
    int exit;
    int visited;
    int pred;
} * tem;

int clock, flag = 0, flg = 0;

struct node *makenode(int i, int x, struct node *A[]) // function to make a node for neighbour and attach it to the associated list
{
    struct node *ptr = malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        return ptr;
    }
    ptr->item = x;
    ptr->next = NULL;

    if (A[i]->next == NULL)
    {
        A[i]->next = ptr;
        A[i]->end = ptr;
    }
    else
    {
        A[i]->end->next = ptr;
        A[i]->end = ptr;
    }

    return ptr;
}

void *push(int x)
{
    temp = malloc(sizeof(struct node));
    if (temp == NULL)
    {
        exit(1);
    }

    temp->item = x;

    if (topo == NULL)
    {
        topo = temp;
        topo->next = NULL;
    }
    else
    {
        temp->next = topo;
        topo = temp;
    }
}

int poptopo()
{
    int x = topo->item;
    temp = topo;
    topo = topo->next;
    free(temp);
    return x;
}
void DfsExplore(int v1,struct data * G[],struct node * A[])
{
    G[v1]->visited=1;
    if(flag==1)                                                                 //to determine whether dfsexplore is caled from findscc
        {
            if(clock!=0)                                                        //if it is not the first element print space
            {
                printf(" ");
            }
            printf("%d",v1+1);
            flg++;
        }
    G[v1]->entry=clock;
    clock++;
    int c=0;

    struct node * temp=A[v1]->next;
    while(temp!=NULL)
    {
        c++;
        int x=temp->item-1;
        if(G[x]->visited==0)
        {
            G[x]->pred=v1+1;
            DfsExplore(x,G,A);
        }
       
        temp=temp->next;
    }
    G[v1]->exit=clock;
    if(flag!=1)
    {
        push(v1);
    }
    clock++;
    
}

void DepthFirstExpl(int v1, struct data *G[], struct node *A[], int n)
{
    clock = 0;
    DfsExplore(v1, G, A);
    for (int i = 0; i < n; i++)
    {
        if (G[i]->visited == 0)
        {
            DfsExplore(i, G, A);
        }
    }
}

void printdata(int n, struct data *G[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d\n", G[i]->entry, G[i]->exit, G[i]->pred);
    }
}

void printedges(int n, struct node *B[])
{
    for (int i = 0; i < n; i++)
    {
        temp = B[i]->next;
        while (temp != NULL)
        {
            printf("%d ", temp->item);
            temp = temp->next;
        }
        printf("-1\n");
    }
}

void FindSCC( struct data *G1[], struct node *B[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        int vertex = poptopo();
        if (G1[vertex]->visited == 0)
        {
            clock = 0;
            cnt = 1;
            flag = 1;
            DfsExplore(vertex, G1, B);
        }
        if (cnt == 1 && flg != n)
        {
            printf("\n");
        }
    }
}

int main()
{
    int n, m, ind1, ind2;

    struct node *abc;
    scanf("%d", &n); // input number of vertices
    struct node *A[n];

    for (int k = 0; k < n; k++)
    {
        A[k] = (struct node *)malloc(sizeof(struct node));
        if (A[k] == NULL)
        {
            exit(1);
        }
        A[k]->item = k + 1;
        A[k]->next = NULL;
    }

    for (int k = 0; k < n; k++)
    {
        scanf("%d", &m);
        while (m != -1)
        {
            abc = makenode(k, m, A);
            if (abc == NULL)
            {
                exit(1);
            }
            scanf("%d", &m);
        }
    }

    struct node *B[n];
    for (int k = 0; k < n; k++)
    {
        B[k] = (struct node *)malloc(sizeof(struct node));
        if (B[k] == NULL)
        {
            exit(1);
        }
        B[k]->item = k + 1;
        B[k]->next = NULL;
    }

    for (int k = 0; k < n; k++)
    {
        temp1 = A[k]->next;
        while (temp1 != NULL)
        {
            m = temp1->item;
            abc = makenode(m - 1, k + 1, B);
            if (abc == NULL)
            {
                exit(1);
            }
            temp1 = temp1->next;
        }
    }

    int startingvertex;
    scanf("%d", &startingvertex); // input the starting vertex for DFS

    struct data *G[n];
    for (int i = 0; i < n; i++)
    {
        G[i] = (struct data *)malloc(sizeof(struct data));
        if (G[i] == NULL)
        {
            exit(1);
        }
        G[i]->vertexno = i + 1;
        G[i]->visited = 0;
        G[i]->entry = -1;
        G[i]->exit = -1;
        G[i]->pred = -1;
    }

    printedges(n, B);
    DepthFirstExpl(startingvertex - 1, G, A, n);
    

    struct data *G1[n];
    for (int i = 0; i < n; i++)
    {
        G1[i] = (struct data *)malloc(sizeof(struct data));
        if (G1[i] == NULL)
        {
            exit(1);
        }
        G1[i]->vertexno = i + 1;
        G1[i]->visited = 0;
        G1[i]->entry = -1;
        G1[i]->exit = -1;
        G1[i]->pred = -1;
    }

    FindSCC(G1, B, n);

    return 0;
}
