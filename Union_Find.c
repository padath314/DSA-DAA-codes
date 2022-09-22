#include<stdio.h>
#include<stdlib.h>

//Structure to save vertex
struct vertex
{
    int v;
    struct vertex *parent;
    int rank;
};

//Makeset
struct vertex * Makeset(int v)
{
    struct vertex * abc = malloc(sizeof(struct vertex));
    if(abc == NULL)
    {
        return abc;
    }
    abc->v = v+1;
    abc->parent=abc;
    abc->rank=0;
    return abc;
}

struct vertex * z;
struct vertex * Find( struct vertex * x)
{
    // struct vertex * y = x;
    // while(y->parent != y )
    // {
    //     y = y->parent;
    // }

    // z = x;

    // struct vertex * p;

    // while( z->parent !=z)
    // {
    //     p = z->parent;
    //     z->parent = y;
    //     z = p;
    // }

    // return y;
    
    //recursive find
    if( x->parent == x)
    {
        return x;
    }

    z = Find(x->parent);
    x->parent = z;
    return z;
}

struct vertex * Union( struct vertex *x, struct vertex *y)
{
    struct vertex * p1, *p2;
    p1 = Find(x);
    p2 = Find(y);
    if(p1==p2)
    {
        return p1;
    }
    int r1,r2;
    r1 = p1->rank;
    r2 = p2->rank;
    if(r1 == r2)
    {
        p2->parent = p1;
        p1->rank += 1;
        return p1;
    }
    else if(r1<r2)
    {
        p1->parent = p2;
        return p2;
    }
    else
    {
        p2->parent = p1;
        return p1;
    }
}

int main()
{
    //number of vertices
    int n;
    scanf("%d",&n);

    //array of pointers
    struct vertex * A[n];

    for(int i=0;i<n;i++)
    {
        A[i] = Makeset(i);
    }

    int x,y,v1,v2;
    struct vertex * temp;
    do
    {
        scanf("%d",&x);
        switch(x)
        {
            //Find
            case 1 : 
                scanf("%d",&y);
                printf("%d\n",Find(A[y-1])->v);
                break;
            //Union
            case 2 :
                scanf("%d %d",&v1,&v2);
                temp = Union(A[v1-1],A[v2-1]);
                printf("%d %d\n",temp->v,temp->rank);
                break;
            //Print
            case 3 :
                for(int i=0;i<n;i++)
                {
                    printf("%d %d\n",A[i]->v,Find(A[i])->v);
                }
                break;
            //exit
            case 4 : exit(0);
            default : break;
        }
    } while (x!=4);
    
    return 0;
}
