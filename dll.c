#include<stdio.h>
#include<stdlib.h>
struct node																	//node 
{
	int item;
	struct node * prev;
	struct node * next;
}*first,*last,* ptr;														//pointers

int main()
{
	int n;																	//number of elements
	int x;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		ptr=(struct node *)malloc(sizeof(struct node));						//allocate space
		if(ptr==NULL)
		{
			printf("ERROR");
			exit(1);
		}
		scanf("%d",&x);														//input element
		ptr->item=x;														//store into node
		if(i==0)															//if its the first element
		{
			last=ptr;
			first=last;
			first->prev=NULL;
			first->next=NULL;
			
		}
		else																//link the new node to the list
		{
			last->next=ptr;
			ptr->prev=last;
			last=ptr;
			last->next=NULL;
		}
			
	}
	
	ptr=first;
	while(ptr!=NULL)														//print list from front to back
	{
		x=ptr->item;
		printf("%d\n",x);
		ptr=ptr->next;
	}
	
	ptr=last;
	while(ptr!=NULL)														//print list from back to front
	{
		x=ptr->item;
		printf("%d\n",x);
		ptr=ptr->prev;
	}
	
	
	ptr=first;																//delete the first element
	first=first->next;
	first->prev=NULL;
	free(ptr);
	
	ptr=last;																//delete the last element
	last=last->prev;
	last->next=NULL;
	free(ptr);
	
	ptr=first;
	while(ptr!=NULL)
	{
		x=ptr->item;
		printf("%d\n",x);
		ptr=ptr->next;
	}
	
	ptr=last;
	while(ptr!=NULL)
	{
		x=ptr->item;
		printf("%d\n",x);
		ptr=ptr->prev;
	}
	
	return 0;
}
	
	
		