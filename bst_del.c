#include<stdio.h>
#include<stdlib.h>
struct node
{
    int key;                                                                    
    struct node * left;
    struct node * right;
    struct node * parent;
}*curptr,* prev,* pointer;

void check(struct node * ptr)
{
    if(ptr==NULL)
    {
        printf("Insert Fail\n");
    }
}

void foundornot(struct node * ptr)
{
    if(ptr!=NULL)
        printf("Found\n");
    else
        printf("Not Found\n");
}

struct node * insert(struct node ** root, int x)
{

    if(*root==NULL)
    {
        struct node * newptr=malloc(sizeof(struct node));
        newptr->key=x;
        newptr->left=NULL;
        newptr->right=NULL;
        newptr->parent=NULL;
        *root=newptr;
        return newptr;
    }
    else if(x<=(*root)->key)
    {
        curptr=insert(&((*root)->left),x);
        curptr->parent=*root;
        (*root)->left=curptr;
        return *root;
    }
    else
    {
        curptr=insert(&((*root)->right),x);
        curptr->parent=*root;
        (*root)->right=curptr;
        return *root;
    }

}

struct node * search(struct node * root, int x)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(root->key==x)
    {
        return root;
    }
    else if(root->key>=x)
    {
        return search(root->left,x);
    }
    else if(root->key<x)
    {
        return search(root->right,x);
    }
   
}

void inorder(struct node * curptr)
{
    if(curptr==NULL)
    {
        return;
    }
    else
    {
        inorder(curptr->left);
        printf("%d\n",curptr->key);
        inorder(curptr->right);
    }
}
void preorder(struct node * curptr)
{
    if(curptr==NULL)
    {
        return;
    }
    else
    {
        printf("%d\n",curptr->key);
        preorder(curptr->left);
        preorder(curptr->right);
    }
}
void postorder(struct node * curptr)
{
    if(curptr==NULL)
    {
        return;
    }
    else
    {
        postorder(curptr->left);
        postorder(curptr->right);        
        printf("%d\n",curptr->key);
    }
}
int abc(struct node * ptr,int x)
{
    if(ptr==NULL)
    {
        if(x==0)
         printf("No predecessor\n");
        else
         printf("No successor\n");
    }
    else 
         printf("%d\n",ptr->key);
}
struct node * predecessor(struct node* root,struct node * p)
{
     if(p==NULL)
        return NULL;
     else if(p->left!=NULL)
     {
         curptr=p->left;
         while(curptr->right!=NULL)
         {
             curptr=curptr->right;
         }
         return curptr;
     }
     else
     {
         curptr=p;
         prev=curptr->parent;
         while(prev!=NULL&&curptr==prev->left)
         {
             curptr=prev;
             prev=curptr->parent;
         }
         return prev;
     }
}
struct node * successor(struct node * root,struct node * p)
{
         if(p==NULL)
        return NULL;
     else if(p->right!=NULL)
     {
         curptr=p->right;
         while(curptr->left!=NULL)
         {
             curptr=curptr->left;
         }
         return curptr;
     }
     else
     {
         curptr=p;
         prev=curptr->parent;
         while(prev!=NULL&&curptr==prev->right)
         {
             curptr=prev;
             prev=curptr->parent;
         }
         return prev;
     }
}

struct node * delet(struct node * ptr, struct node * root)
{
    if(ptr==NULL)
    {
        printf("Deletion Fail");
        return root;
    }
    if(ptr->left==NULL&&ptr->right==NULL)                               //leaf node case
    {
        if(ptr->parent==NULL)
        {
            root=NULL;
        }
        else if(ptr->parent->left=ptr)
        {
            ptr->parent->left=NULL;
        }
        else if(ptr->parent->right=ptr)
        {
            ptr->parent->right=NULL;
        }
        free(ptr);
        return root;
    }

    else if(ptr->right==NULL)
    {
        if(ptr->parent->right==ptr)
        {
            ptr->parent->right=ptr->left;
            ptr->left->parent=ptr->parent;
        }
        else if(ptr->parent->left==ptr)
        {
            ptr->parent->left=ptr->left;
            ptr->left->parent=ptr->parent;
        }
        else
        {
            ptr->left->parent=NULL;
            root=ptr->parent;
        }
        free(ptr);
        return root;

    }
    else if(ptr->left==NULL)
    {
        if(ptr->parent->right==ptr)
        {
            ptr->parent->right=ptr->right;
            ptr->right->parent=ptr->parent;
        }
        else if(ptr->parent->left==ptr)
        {
            ptr->parent->left=ptr->right;
            ptr->right->parent=ptr->parent;
        }
        else
        {
            ptr->right->parent=NULL;
            root=ptr->parent;
        }
        free(ptr);
        return root;

    }
    else                                                                // both subrtrees exist
    {
        struct node * sptr=successor(root,ptr);
        int s=sptr->key;
        root=delet(sptr,root);
        ptr->key=s;
        return root;
    }
}
int main()      
{
    int x,n;                                                                    
    struct node * root=NULL,*count;
    
    do 
    {
        scanf("%d",&x);
        switch(x)
        {
            case 1 : 
                     scanf("%d",&n);
                     curptr=root;
                     curptr=insert(&root,n);                                    
                     check(curptr);
                     break;
            case 2 : 
                     scanf("%d",&n);
                     count=search(root,n);
                     foundornot(count);
                     break;
            case 3 : 
                     curptr=root;
                     inorder(curptr);
                     break;
            case 4 : 
                     curptr=root;
                     preorder(root);
                     break;
            case 5 : 
                     curptr=root;
                     postorder(root);
                     break;
            case 6 : 
            	     scanf("%d",&n);
                     curptr=search(root,n);
                     pointer=predecessor(root,curptr);
                     if(curptr==NULL)
                     {
                         printf("Invalid Input\n");
                     }
                     else
                         abc(pointer,0);
                     break;
            case 7 :
            	     scanf("%d",&n);
                     curptr=search(root,n);
                     pointer=successor(root,curptr);
                     if(curptr==NULL)
                     {
                         printf("Invalid Input\n");
                     }
                     else
                         abc(pointer,1);
                     break;
            case 8 :
                     scanf("%d",&n);
                     curptr=search(root,n);
                     root=delet(curptr,root);
                     break;



            default: exit(0);
        }
    } while(1);

    return 0;

}
