#include<stdio.h>
#include<stdlib.h>
struct node
{
    int item;
    struct node * next;
}* top;

int IsEmpty()
{
    if(top==NULL)
        return 0;
    else
        return 1;

}

int Push()
{
    int x;
    scanf("%d",&x);
    struct node * node0=(struct node *)malloc(sizeof(struct node));
    if(node0!=NULL)
    {
        node0->item=x;
        node0->next=top;
        top=node0;
        return 0;
    }
    else
        return 1;
    
}

int Top()
{
    if(top==NULL)
    {
        return 1;
    }
    printf("%d\n",top->item);
    return 0;
}

int Pop()
{
    if(top==NULL)
    {
        return 1;
    }
    printf("%d\n",top->item);
    struct node * temp=top;
    top=top->next;
    free(temp);
    return 0;
}

int Display()
{
    int err=IsEmpty(top);
    if(err==0)
        return 1;
    else
    {
        struct node * cur_ptr;
        cur_ptr=top;
        while(cur_ptr!=NULL)
        {
            printf("%d\n",cur_ptr->item);
            cur_ptr=cur_ptr->next;
        }
        return 0;

    }
}

int main()
{
    int x=0,error_code=-1,var;
    top=NULL;
    do
    {
        scanf("%d",&x);
        switch(x)
        {
            case 0 : var=IsEmpty();
                     if(var==0)
                        printf("Empty\n");
                     else
                        printf("Non Empty\n");
                     break;
            case 1 : error_code=Push();
                     if(error_code==1)
                     {
                         printf("Push Failure\n");
                         exit(1);
                     } 
                     break;
            case 2 : error_code=Pop();
                     if(error_code==1)
                     {
                         printf("Pop Failure\n");
                         exit(1);
                     } 
                     break;
            case 3 : error_code=Top();break;
            case 4 : error_code=Display();
                     if(error_code==1)
                        printf("Empty List\n");
                    break;
            case 5 : exit(0);break;
            default: exit(0);
        }
 
    } while(1);

    return 0;
    
}