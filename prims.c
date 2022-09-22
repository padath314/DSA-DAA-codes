#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// number of vertices
int n;

//structure for saving vertex u and its cost value- for heap
struct tuple
{
    int vertex;
    int key;
};

//for neighbour
struct neighbour
{
    int v;
    struct neighbour *next;
    int weight;
} * abc;

//for starting vertex
struct node
{
    int item;
    int cost;
    int indexinheap;
    int pred;
    struct neighbour *next;
    struct neighbour *end;
};

// functions for heap
int parent(int i)
{
    return (i - 1) / 2;
}
int left(int i)
{
    return 2 * i + 1;
}
int right(int i)
{
    return 2 * i + 2;
}

//fn to swap to vertices of the heap as well as swap their heap indeices in the vertex array A 
void swap(struct tuple *a, struct tuple *b, struct tuple *T[], struct node *A[])
{
    int i = A[a->vertex - 1]->indexinheap;
    A[a->vertex - 1]->indexinheap = A[b->vertex - 1]->indexinheap;
    A[b->vertex - 1]->indexinheap = i;

    struct tuple x = *a;
    *a = *b;
    *b = x;
}

// function to make a node for neighbour and attach it to the associated list
struct neighbour *makenode(int i, int x, int y, struct node *A[])
{
    struct neighbour *ptr = malloc(sizeof(struct neighbour));
    if (ptr == NULL)
    {
        return ptr;
    }
    ptr->v = x;
    ptr->next = NULL;
    ptr->weight = y;

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

// Minheapify fn
void MinHeapify(struct tuple *T[], struct node *A[], int posn)
{
    int smallest = posn;
    if (left(posn) <= n - 1 && T[left(posn)]->key <= T[posn]->key)
    {
        smallest = left(posn);
    }
    if (right(posn) <= n - 1 && T[right(posn)]->key <= T[smallest]->key)
    {
        smallest = right(posn);
    }
    if (smallest == posn)
    {
        return;
    }
    else
    {
        swap(T[posn], T[smallest], T, A);
    }
    MinHeapify(T, A, smallest);
}

// Sift up fn
void Siftup(struct tuple *T[], int i, struct node *A[])
{
    while (i > 0 && T[i]->key < T[parent(i)]->key)
    {
        swap(T[i], T[parent(i)], T, A);
        i = parent(i);
    }
}

// decreasekey fn
void decreasekey(int i, int value, struct tuple *T[], struct node *A[])
{
    T[i]->key = value;
    Siftup(T, i, A);
}

// extract min
struct tuple extractmin(struct tuple *T[], struct node *A[])
{
    struct tuple *temp = T[0];
    T[0] = T[n - 1];
    n--;
    MinHeapify(T, A, 0);
    A[temp->vertex - 1]->cost = temp->key;
    return *temp;
}

//add vertex to S a vertex and update the cost of its neighbours if necessary
void addtoS(struct tuple v, struct node *A[], struct tuple *T[])
{
    int m = 0, i = 0, weight = 0;
    struct neighbour *temp = A[v.vertex - 1]->next;
    //traverse through neighbour linked list
    while (temp != NULL)
    {
        m = temp->v;
        i = A[m - 1]->indexinheap;
        //check if the neighbour is already in S, ie not in the heap
        if (i == -1)
        {
            temp = temp->next;
            continue;
        }
        weight = temp->weight;
        //update the cost
        if (T[i]->key > weight)
        {
            A[m - 1]->pred = v.vertex;
            decreasekey(i,weight, T, A);
        }
        temp = temp->next;
    }
}
int flag;
void prims(struct node *A[], struct tuple *T[])
{
    // add to s and update costs
    while (n != 0)
    {
        struct tuple v = extractmin(T, A);
        addtoS(v, A, T);
        A[v.vertex - 1]->indexinheap = -1;
        if(flag!=0)
        {
            printf("%d-%d\n", A[v.vertex-1]->pred,v.vertex,v.key);
        }
        flag++;
    }
}

int main()
{
    int N, m, wg;
    // input the number of vertices
    scanf("%d", &N);

    n = N;

    // array of struct node
    struct node *A[n];

    // heap
    struct tuple *T[n];

    // initialising heap
    for (int i = 0; i < N; i++)
    {
        T[i] = malloc(sizeof(struct tuple));
        if (T[i] == NULL)
        {
            exit(1);
        }
        T[i]->vertex = i + 1;
        T[i]->key = 1000;
    }

    // initialise array
    for (int k = 0; k < N; k++)
    {
        A[k] = malloc(sizeof(struct node));
        if (A[k] == NULL)
        {
            exit(1);
        }
        A[k]->item = k + 1;
        A[k]->end = NULL;
        A[k]->next = NULL;
        A[k]->indexinheap = k;
        A[k]->pred = -1;
        A[k]->cost = 0;
    }
    // input the neighbours and make linked list associated with each element of the array
    for (int k = 0; k < N; k++)
    {
        scanf("%d", &m);
        while (m != -1)
        {
            scanf("%d", &wg);
            abc = makenode(k, m, wg, A);
            if (abc == NULL)
            {
                exit(1);
            }
            scanf("%d", &m);
        }
    }

    // input source vertex
    int s;
    scanf("%d", &s);

    // decrease d(s) to 0
    decreasekey(A[s - 1]->indexinheap, 0, T, A);
    A[s - 1]->indexinheap = 0;



    // Prims function
    flag = 0;
    prims(A, T);

   
    return 0;
}