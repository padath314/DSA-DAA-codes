#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

struct tree                                                                     //struct for expression tree
{
    char item;                                                                  
    struct tree * left;                                                         
    struct tree * right;
};

struct node                                                                     //struct for node
{
    struct tree item ;
    struct node * next;
}*top,*temp;                                                                    

int Push(struct tree * tr)                                                      //push function to push an expression tree into stack
{
    struct node * node0=malloc(sizeof(struct node));
    if(node0==NULL)
    {
        return 1;
    }
    node0->item=*tr;
    node0->next=top;
    top=node0;
    return 0; 
    
}

struct tree * Pop()                                                             //pop function 
{
    if(top==NULL)
    {
        return NULL;
    }
    struct tree * nw=malloc(sizeof(struct tree));
    if(nw==NULL)
    {
    	return NULL;
    }
    *nw =(top->item);
    temp=top;
    top=top->next;
    free(temp);
    return nw;
}

void inorder(struct tree * curptr)                                              //function to do inorder traversing with proper paranthesis
{
    if(curptr==NULL)
    {
        return;
    }
    if(curptr->left!=NULL)
        printf("(");
    inorder(curptr->left);
    printf("%c",curptr->item);
    inorder(curptr->right);
    if(curptr->right!=NULL)
        printf(")");
}

void preorder(struct tree * curptr)                                             //function to do preordertraversing with proper paranthesis
{
    if(curptr==NULL)
    {
        return;
    }
    printf("%c",curptr->item);
    preorder(curptr->left);
    preorder(curptr->right);
}

int main()                                                                      
{
    char exp[100];                                                              //string to save the expression
    scanf("%s",exp);                                                            

    int i=0;            
    while(exp[i]!='\0')                                                         //loop to take character by character
    {
        if(isalpha(exp[i]))                                                     //if alphabet
        {
            struct tree * new=(struct tree *)malloc(sizeof(struct tree));       //define expression tree
            if(new==NULL)
            {
                return 1;
            }
            new->item=exp[i];                                                   //save character into root 
            new->left=NULL;
            new->right=NULL;
            Push(new);                                                          //push into stack 
        }
        else
        {
            struct tree * newptr=(struct tree *)malloc(sizeof(struct tree));    //define expression tree
            if(newptr==NULL)
            {
                return 1;
            }
            newptr->item=exp[i];                                                //save operator to root
            newptr->right=Pop();                                                //pop the operand out and save to right
            newptr->left=Pop();                                                 //pop the operand out and save to left
            Push(newptr);                                                       //push into stack
        }
        i++;                                                                    
    }
    struct tree * ptr=&(top->item);                                             //
    inorder(ptr);                                                               //inorder trvaersal
    printf("\n");                                                               //
    preorder(ptr);                                                              //preorder
    printf("\n");                                                               //
    return 0;
   
}