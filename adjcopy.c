#include<stdio.h>
#include<stdlib.h>
struct node
{
    int item;
    struct node * neigh;
};
/*void printadj(struct node A[],int n)
{
    struct node cptr;
    for(int i=0;i<n;i++)
    {
        cptr=A[i];
        printf("%d ",cptr.item);
        while(cptr.neigh!=NULL)
        {
            printf("%d ",cptr.item);
            cptr=*cptr.neigh;
        }
        
        printf("\n");
    }
}*/
void adjcreate(struct node * V[],int i,int j)
{
    struct node* adj=(struct node*)malloc(sizeof(struct node));
    struct node* curr = (struct node*)malloc(sizeof(struct node));
    adj->item=j;
    adj->neigh=NULL;
    curr=V[i];
        if(curr->neigh==NULL)
        {
            
            V[i]->neigh=adj;
            
        }
        //printf("%d\n",curr);
        else
        {
            while(curr->neigh!=NULL)
            {
                curr = curr->neigh;
                //printf("*");
            }
        }
        curr->neigh= adj;
}
   
int main()
{
    int n,m;
    scanf("%d",&n);
    scanf("%d", &m);
    struct node* V[n];
    V[n]=(struct node*)malloc(n*sizeof(struct node));
    struct node *adj2, *adj;
    for(int i=0;i<n;i++)
    {
        V[i]->item=i;
        V[i]->neigh=NULL;
    }
    int i,j;
    
    
    
    for(int c=0;c<m;c++)
    {
        scanf("%d %d", &i,&j);
        adjcreate(V,i,j);
        adjcreate(V,j,i);
        
        
        
        
        

        
        /*adj2=(struct node*)malloc(sizeof(struct node));
        adj2->item=i;
        struct node* curr2 = V[j].neigh;
        while(curr2!=NULL)
        {
            curr2 = curr2->neigh;
            printf("*");
        }
        curr2 = adj2;
        */

    }
    struct node *cptr;
    for(int i=0;i<n;i++)
    {
        cptr=V[i]->neigh;
        
        //printf("%d ",cptr->item);
        if(cptr==NULL)
        {
            printf("Nil\n");
            continue;
        }
        while(cptr!=NULL)
        {
            printf("%d ",cptr->item);
            cptr=cptr->neigh;
        }
        
        printf("\n");
    }
    //printadj(V,n);
    
}