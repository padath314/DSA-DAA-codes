#include<stdio.h>
#include<stdlib.h>
void insert(int x,FILE *p1,FILE *p2,int i)
{
    int j=i-1;
    FILE *p3;
    p3=fopen("input2.txt","r");
    int y;
    fseek(p3,(i+1)*sizeof(int),SEEK_SET);
    fread(&y,sizeof(int),-1,p3);
    while(y>x&&j>=0)
    {
        j--;
    }
    fseek(p3,sizeof(int),SEEK_SET);
    fwrite(&x,sizeof(int),1,p3);
    while(j<i)
    {
        fread(&y,sizeof(int),1,p1);
        fwrite(&y,sizeof(int),1,p3);
        j++;
    }
    //writing back to input2.txt
    int c=0;
    while(fread(&c,sizeof(int),1,p3))
    {
        fwrite(&c,sizeof(int),1,p1);
    }

}

void insert_sort(FILE *p1,FILE *p2,long n)
{
    int x;
    for(int i=1;i<n;i++)
    {
        fread(&x,sizeof(int),1,p1);
        insert(x,p1,p2,i);
    }

   
}
int main()
{
    FILE *p1,*p2;
    p1=fopen("input2.txt","r+");            //pointer to read and write from input file
    p2=fopen("temp2.txt","w+");              //pointer to write and read in a temporary file

    fseek(p1,0,SEEK_END);                   //placing pointer at the end of the file
    long size = ftell(p1)/sizeof(int);      //finding the current position position of the pointer ie size of the file and dividing it by sizeof int to find the length of the array
    fseek(p1,0,SEEK_SET);                   //placing the pointer back at the start of the file
    insert_sort(p1,p2,size);
    

    return 0; 
 
}