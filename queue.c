#include<stdio.h>
#include<stdlib.h>
struct node                                                             //define node             
{
    int item;                                                                   
    struct node * next;
}* nw;                                                                  //node pointer

struct queue                                                            //struct containing queue parameters
{
    struct node * front;
    struct node * rear;
}qe;                                                                    //define qe

int IsEmpty()                                                           //function to check whether the qe is empty
{
    if(qe.rear==NULL)
        return 1;
    else 
        return 0;
}

int Enqueue()                                                           //function to add a node to the queue
{
    int x;
    scanf("%d",&x);                                                     //input the element
    nw=(struct node * )malloc(sizeof(struct node));                     //allocate space for new node and save the location to pointer nw
    if(nw==NULL)                                                        //if space did not get allocated
        return 1;
    nw->item=x;                                                         
    nw->next=NULL;
  
    if(qe.rear==NULL)                                                   //if queue is empty assign front and rear
    {
        qe.rear=nw;
        qe.front=qe.rear;
    }
    else                                                                //linking node to the rear end
    {
    	qe.rear->next=nw;
    	qe.rear=nw;
    }
    
    return 0;
}

int Dequeue()                                                           //function to delete element from the rear end of the queue
{
    if(qe.front==NULL)                                                  //if queue is empty
        return 1;
    int x=qe.front->item;                                               //save the element to be deleted
    struct node * temp=qe.front;                                        
    qe.front=qe.front->next;
    free(temp);
    printf("%d\n",x);
    return 0;
}

void Peek()                                                             //function to display the front element of the queue
{
    int x=qe.front->item;
    printf("%d\n",x);
}

int Display()                                                          //function to display the elements of the queue
{
    if(qe.front==NULL)                                                 // empty
        return 1;
    
    struct node * ptr;
    ptr=qe.front;                                                      //vary ptr from front to rear
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->item);
        ptr=ptr->next;
    }
    return 0;

}

int main()
{
    int x,error_code;                                                  //variable error_code to confirm whether fn worked properly
    qe.front=NULL;
    qe.rear=NULL;

    do
    {
        scanf("%d",&x);
        switch(x)
        {
            case 0 : error_code=IsEmpty();
                     if(error_code==1)
                        printf("Empty\n");
                     else
                        printf("Non Empty\n");
                     break;
            case 1 : error_code=Enqueue();
                     if(error_code==1)
                        printf("Enqueue Failure\n");
                     break;
            case 2 : error_code=Dequeue();
                     if(error_code==1)
                        printf("Dequeue Failure\n");
                     break;
            case 3 : Peek();break;
            case 4 : error_code=Display();
            	      if(error_code==1)
            	      	printf("Empty List");
            	      break;
                     
            case 5 : exit(0);
        }
        
    }while(1);
    
    return 0;
}
        
        
        
        