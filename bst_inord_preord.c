#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node * left;
    struct node * right;
}* ROOT, * CURR;

int Index(int * ar, int item)
{
    int i = 0;
    while(ar[i]!=item)
    {
        i++;
    }
    return i;
}

MakeTree(int *in, int* pre, int left, int right, int preorder_pos)
{
    int curr = pre[preorder_pos];
    CURR->key = curr;
    if(left == right)
    {
        return;
    }
    if (Index(in, curr)>left)
    {
        CURR = CURR->left;
        CURR = malloc(sizeof(struct node));
        MakeTree(in, pre, left, Index(in, curr), preorder_pos+1);
    }
    if (Index(in, curr)<right)
    {
        CURR = CURR->right;
        CURR = malloc(sizeof(struct node));
        MakeTree(in, pre, Index(in, curr), right, preorder_pos+1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int inorder[n], preorder[n];
    for (int i=0; i<n; i++)
    {
        scanf("%d", inorder+i);
    }
    printf("\n");
    for (int i=0; i<n; i++)
    { 
        scanf("%d", preorder+i);
    }
    CURR = ROOT;
    CURR = malloc(sizeof(struct node));
    MakeTree(inorder, preorder,0,n-1,0);
}