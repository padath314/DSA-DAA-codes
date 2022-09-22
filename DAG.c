#include <stdio.h>
#include <stdlib.h>
int dagornot; // globalvariable to dave if graph is dag or not
struct node   // struct to save neighbours in
{
    int item;
    struct node *next;
    struct node *end;
} * temp, *topo;

struct data // struct to save other data related to a vertex
{
    int vertexno;
    int entry;
    int exit;
    int visited;
    int pred;
} * tem;

int clock; // global clock

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
void DfsExplore(int v1, struct data *G[], struct node *A[]) // DFS Explore fn
{
    G[v1]->visited = 1;
    G[v1]->entry = clock;
    clock++;
    int c = 0;

    struct node *temp = A[v1]->next;
    while (temp != NULL)
    {
        c++;
        int x = temp->item - 1;
        if (G[x]->visited == 0)
        {
            G[x]->pred = v1 + 1;
            DfsExplore(x, G, A);
        }
        else // if the encountered vertex is visited we check if it is a backedge
        {
            if (G[x]->exit == -1) // by checking if it is exitted from
            {
                dagornot = 0;
            }
        }
        temp = temp->next;
    }
    G[v1]->exit = clock;
    push(v1);
    clock++;
}

void DepthFirstExpl(int v1, struct data *G[], struct node *A[], int n) // Depth First Search fn
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

void printdata(int n, struct data *G[]) // print data fn to print entry time, exit time, predecessor
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d\n", G[i]->entry, G[i]->exit, G[i]->pred);
    }
}

void printbackedge(struct data *G[], struct node *A[], int n) // fn to print the backedges along with other data
{
    int v;
    int ex1, ex2;
    for (int i = 0; i < n; i++)
    {
        temp = A[i]->next;
        while (temp != NULL)
        {
            ex1 = G[i]->exit;
            ex2 = G[temp->item - 1]->exit;
            if (ex1 < ex2)
            {
                v = temp->item - 1;
                printf("%d %d %d %d\n", G[v]->entry, G[i]->entry, G[i]->exit, G[v]->exit);
            }
            temp = temp->next;
        }
    }
}

int main()
{
    int n, m, ind1, ind2;

    dagornot = 1; // let us assume the graph is acyclic
    struct node *abc;
    scanf("%d", &n);   // input number of vertices
    struct node *A[n]; // array of struct pointers

    for (int k = 0; k < n; k++)
    {
        A[k] = malloc(sizeof(struct node));
        if (A[k] == NULL)
        {
            exit(1);
        }
        A[k]->item = k + 1;
        A[k]->end = NULL;
        A[k]->next = NULL;
    }

    for (int k = 0; k < n; k++) // input the neighbours and make linked kist associated with each element of the array
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

    struct node *bk[n];

    int startingvertex;
    scanf("%d", &startingvertex); // input the starting vertex for DFS

    struct data *G[n]; // array to store other data
    for (int i = 0; i < n; i++)
    {
        G[i] = malloc(sizeof(struct data));
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

    DepthFirstExpl(startingvertex - 1, G, A, n);
    printdata(n, G);
    if (dagornot == 0)
    {
        printf("Not a DAG\n");
        printbackedge(G, A, n); // print backedges
    }
    else if (dagornot == 1)
    {
        printf("DAG\n");
        // pop the vertices from topo stack
        for (int i = 0; i < n; i++)
        {
            int x = poptopo();
            printf("%d\n", x + 1);
        }
    }

    return 0;
}