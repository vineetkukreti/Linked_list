#include<stdio.h>
#define max 5

int queue[max];
int front=-1;
int rear=-1;

int enqueue(int a)
{
	if((front==0&&rear==max-1)||front==rear+1)
	{
		printf("Queue is full!!!\n");
	}
	if(front==-1)
	{
		front=0;
		rear=0;
	}
	else
	{
		if(rear==max-1)
			rear=0;
		else
		    rear=rear+1;
	}
	queue[rear]=a;
}
void dequeue()
{
	if(front==-1)
	{
		printf("Queue is empty!!!!!\n");
		return;
	}
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
	{
		if(front==max-1)
			front=0;
		else
			front=front+1;
	}
}

void display()
{
	int fpos=front,rpos=rear;
	
	if(front==-1)
	   {
	   		printf("Queue is empty!!!!!\n");
	   		return;
	   }
	printf("Queue elements : \n");
	if(fpos<=rpos)
	{
		while(fpos<=rpos)
		{
			printf("%d\n",queue[fpos]);
			fpos++;
		}
	}
	else
	{
		while(fpos<=max-1)
		{
			printf("%d\n",queue[fpos]);
			fpos++;
		}
		fpos=0;
		while(fpos<=rpos)
		{
			printf("%d\n",queue[fpos]);
			fpos++;
		}
	}
	printf("\n");
}
int main()
{
	int choice,item;
	do{
		printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the element : ");
				scanf("%d",&item);
				enqueue(item);
			    break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Exiting the program................");
				break;
		    default:
		    	printf("You entered the wrong choice!!!!!!");
		}
	}while(choice!=4);
	return 0;
}
