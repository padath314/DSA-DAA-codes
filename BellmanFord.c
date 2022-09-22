/* Q2. Write a C program that takes a weighted directed graph G, and a vertex s of G as input and computes the shortest path distance from 
s to all vertices of G using the Bellman-Ford algorithm which includes the updateFlag based optimisation and negative cycle detection. 
If there is a negative weight cycle reachable from s in G, your program should print vertices of such a cycle in the order of the cycle. 
Your algorithm should work in $O(n+mn)$ time and with only $O(n)$ additional space, other than storing the input edge-list. 
It should work faster as expected if the algorithm converges in lesser number of rounds.

Input format :
Line 1 : Number of vertices (assume vertices are numbered 1 to n).
Line 2 : Number of edges (assume this number is m).
Line 2+i, where 1<=i<=m : Endpoints of i^th edge of G, separated by a space.

Instructions: For edge relaxations, follow the same order as in the input edge-list. For printing negative weight cycle (if exists), 
consider the the vertex v whose d value got updated earliest in the n^th round of edge relaxations and retrace the predecessor pointers from v. 
If v itself is lying on a negative weight cycle, the order of printing the cycle vertices should be such that v is printed as the last vertex of the cycle. 
If v is not lying on a negative weight cycle, the order of printing the cycle vertices should be such that the vertex x of the cycle 
which is the first one to encounter while retracing the path predecessors from v is printed as the last vertex of the cycle. 

Output format : 
a. If the graph has no negative weight cycles reachable from s, then :
Line i, where 1 <= i <= n : If vertex i is reachable from s, print the distance to vertex i, predecessor of vertex i in a shortest s-v path, 
separated by one space each. Assume the predecessor of s is -1. If vertex i is unreachable from s, print "Unreachable". 
b. If the graph has a negative weight cycles reachable from s, then print the vertices of the cycle as per the cyclic order, 
separated by one space each. To decide which cycle to print and in which order, follow the instructions given above.                                             */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

const int infinity = INT_MAX;    //Addition operations cause overflow => check those conditions

typedef struct Edge
{
    int u, v, edge_weight;
} Edge;

typedef struct vertex
{
    int distance, pred,flag; //edit
} vertex;

int no_of_vertices;
int no_of_edges;

void initialize_vertices(vertex v[], int source_vertex)
{
    for(int i = 1; i <= no_of_vertices; i++)
    {
        v[i].distance = infinity;
        v[i].pred = -1;
        v[i].flag = 0; //edit
    }
}

void input_edge_list(Edge edge[])
{
    for(int i = 1; i <= no_of_edges; i++)
    {
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].edge_weight);
    }
}

int Bellman_Ford(int source_vertex, Edge edge_list[], vertex V[])
{ 
    int value = -1;
    initialize_vertices(V, source_vertex);      //All vertices are initialized with infinite distance and pred with -1
    V[source_vertex].distance = 0;
    for(int j = 1; j <= no_of_vertices; j++)
    {
        int updateflag = 0;
        for(int i = 1; i <= no_of_edges; i++)
        {
            if((V[edge_list[i].u].distance != INT_MAX)&&(V[edge_list[i].v].distance > V[edge_list[i].u].distance + edge_list[i].edge_weight))
            {
                V[edge_list[i].v].distance = V[edge_list[i].u].distance + edge_list[i].edge_weight;
                V[edge_list[i].v].pred = edge_list[i].u;
                updateflag = 1;
                if(j == no_of_vertices)
                {
                    value = edge_list[i].v; //edit
                    return value;
                }
            }
        }
        if(updateflag == 0)
            break;
    }
    return value;
}

int flag;
int flag2=0;
void recursive_print_pred(int val, vertex v[])
{
    if(v[val].flag == 1) //edit
    {
        flag = val;
        return;
    }
   
   // if(val == value)
    // {
    //     flag = 1;
    //     return;
    // }
    v[val].flag = 1; //edit
    recursive_print_pred(v[val].pred,v);
    
    if(!flag2)
    {
        printf("%d ", val);
    }
    if(val == flag)
    {
        flag2 = 1;
    }
}

void print_output(int value, vertex v[])
//value will be -1 if no negative edged cycle is found or else will be the vertex whose distance was updated in the last iteration
//So we print the 
{
    if(value == -1)
    {
        for(int i = 1; i <= no_of_vertices; i++)
        {
            if(v[i].distance < infinity)
            {
                printf("%d %d\n", v[i].distance, v[i].pred);
            }
            else
                printf("Unreachable\n");
        }
    }
    else
    { 

        flag = -1;
        recursive_print_pred(value, v);
       
    }
}

void main()
{
    ////////////////////INPUT//////////////////////
    scanf("%d", &no_of_vertices);
    vertex v[no_of_vertices + 1];
    scanf("%d", &no_of_edges);
    Edge edge[no_of_edges + 1];
    input_edge_list(edge);
    int source_vertex;
    scanf("%d", &source_vertex);
    //////////////////////////////////////////////
    int value = Bellman_Ford(source_vertex, edge, v);
    //////////////////OUTPUT//////////////////////
    print_output(value, v);
}