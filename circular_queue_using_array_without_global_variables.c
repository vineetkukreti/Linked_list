#include<stdio.h>
#define MAX 10

void Enqueue(int queue[],int *front,int *rear)
{
	int a;
	printf("\nEnter the element : ");
	scanf("%d",&a);
	if((*front==0&&*rear==MAX-1)||*front==*rear+1)
	{
		printf("\nQueue is full!!!!\n");
	}
	if(*front==-1)
	{
		*front=0;
		*rear=0;
	}
	else
	{
		if(*rear==MAX-1)
		   *rear=0;
		else
		    *rear=*rear+1;
	}
	queue[*rear]=a;
}

void Dequeue(int queue[],int *front,int *rear)
{
	if(*front==-1)
	{
		printf("\nQueue is Empty!!!!\n");
		return;
	}
	if(*front==*rear)
	{
		*front=-1;
		*rear=-1;
	}
	else
	{
		if(*front==MAX-1)
		   *front=0;
		else
		  {
		  	printf("\nDeleted Element From Queue  : %d",queue[*front]);
		  	*front=*front+1;
		  }
	}
}

void Display(int queue[],int front,int rear)
{
	int fpos=front,rpos=rear;
	if(front==-1)
	{
		printf("\nQueue is Empty!!!!!!!\n");
		return;	
	}	
	printf("\nQueue Elements Are  :  \n");
	if(fpos<=rpos)
	{
		while(fpos<=rpos)
		{
			printf("%d	",queue[fpos]);
			fpos++;
		}
	}
	else
	{
		while(fpos<=MAX-1)
		{
			printf("%d	",queue[fpos]);
			fpos++;
		}
		fpos=0;
		while(fpos<=rpos)
		{
			printf("%d",queue[fpos]);
			fpos++;
		}
	}
	printf("\n");
}
int main()
{
	int choice,front=-1,rear=-1;
	int queue[MAX];
	printf("*****MENU*****\n");
	printf("1.Enqueue\n");
	printf("2.Dequeue\n");
	printf("3.Display Queue elements\n");
	printf("4.Exit\n");
	do
	{
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				Enqueue(queue,&front,&rear);
				break;
			case 2:
				Dequeue(queue,&front,&rear);
				break;
			case 3:
				Display(queue,front,rear);
				break;
			case 4:
				printf("\n\nExiting the program........................................");
		}
	}while(choice!=4);
	return 0;
}
