//Circular Linked List program And its Basic Operations 
//Without Global Variables
//Using Double Pointer
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* link;
};
//Creating linked list and inserting nodes from left to right
void create_list(struct node** last,int value)
{
	struct node* p=(struct node*)malloc(sizeof(struct node));
	if(*last==NULL)
	{
		p->data=value;//Enter the value in first node
		p->link=p;//link part of node points to itself
		*last=p;//last pointer points to the node
	}
	else
	{
		p->data=value;//Enter the value to be inserted into the right side of circular linked list
		p->link=(*last)->link;//link part of newnode points to same node as last->next points
		(*last)->link=p;//last->link points to the newnode
		*last=p;//updating the last pointer to the newnode
	}	  
}    
//Function for inserting a node at front of the circular linked list
void Insert_at_front(struct node** last)
{
	int data;
	printf("\nEnter the data to be inserted in front of linked list  :  ");
	scanf("%d",&data);
	struct node* p=(struct node*)malloc(sizeof(struct node));
	if(*last==NULL)
	{
		p->data=data;//Enter the value in first node
		p->link=p;//link part of node points to itself
		*last=p;//last pointer points to the node
	}
	else
	{
		p->data=data;//Enter the value to be inserted into the right side of circular linked list
		p->link=(*last)->link;//link part of newnode points to same node as last->next points
		(*last)->link=p;//last->link points to the newnode
	}	  
}
//Function for adding element after the entered element
void Add_after(struct node** last)
{ 
	int num,data;
	struct node *temp,*n;
	printf("Enter number after which you want to enter a new number  :  ");
	scanf("%d",&num);
	temp=(*last)->link;
	do
	{
		if(temp->data==num)
		{
			n=(struct node*)malloc(sizeof(struct node));
			printf("\nEnter the data to be inserted  :  ");
			scanf("%d",&data);
			n->data=data;
			n->link=temp->link;//newnode points to the same node as temp
			temp->link=n;//now temp points to the new node(temp->link is updated)
			if(temp==*last)
				*last=n;//if temp is the last node then the last pointer points to newnode
			break;
		}
		else
		   temp=temp->link;
	}while(temp!=(*last)->link);
}
//Function to add a node at last of list
void Add_last(struct node** last)
{
	int data;
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	//input data
	printf("Enter the data to inserted  :  ");
	scanf("%d",&data);
	if(*last==NULL)//if newnode is the only node in the list
	   {
	   	 temp->data=data;
	   	 temp->link=temp;
	   	 *last=temp;
	   }
	else
	{
		temp->data=data;//inserting data into the node
		temp->link=(*last)->link;//link part of the new node points to the first node 
		(*last)->link=temp; //link part of last node points to the new node
		*last=temp;//last pointer assigned to newnode so newnode is the last node of linked list 
	}
}
//Function for deleting first node of list
void Delete_first(struct node** last)
{
	struct node *temp;
	if(*last==NULL)
		printf("\nLinked list is Empty");
	else{
		temp=(*last)->link;//temp contains refrence of the first node
		(*last)->link=temp->link;//last node points to the first node
		free(temp);//freeing the memory of the node to be deleted ,from heap
	}
}
//Function for deleting last node from list
void Delete_last(struct node** last)
{
	struct node* temp;
	if(*last==NULL)
		printf("Linked list is Empty!!!");
	temp=(*last)->link;//temp contains the refrence to first node
	//Transversing the list till second last node
	while(temp->link!=*last)
	  temp=temp->link;
	temp->link=(*last)->link;
	*last=temp;
}
//Function for deleting from specific index entered
void Delete_atindex(struct node** last)
{
	int pos,i=1;
	struct node *temp,*position;
	temp=(*last)->link;
	if(*last==NULL)
		printf("Linked list is Empty");
	else{
		printf("\nEnter the position : ");
		scanf("%d",&pos);
		while(i<pos-1)
		{
			temp=temp->link;
			i++;
		}//After the loop ends temp points at the node just before the node to be deleted
		position=temp->link;
		temp->link=position->link;
		free(position);
	}
}
//Function for displaying the data of nodes
void display(struct node** last)//printing nodes from left to right
{
	if(*last==NULL){
	 printf("Linked List is Empty !!!!\n\n");
	 return;
	}
	struct node* p;
	p=(*last)->link;
	printf("\nElements of Linked List  :  \n");
	do
	{
		printf("%d\n",p->data);
		p=p->link;
	}while(p!=(*last)->link);
}
//Driver Code
int main()
{
	int choice,n,data,i;
	struct node* last=NULL;
	
		printf("\n1.Insert an element into the linked list(in last)\n");
		printf("2.Insert an Element in front of linked list\n");
		printf("3.Insert an element after the entered element\n");
		printf("4.Insert an Element at the last of the linked list\n");
		printf("5.Delete the front element of linked list\n");
		printf("6.Delete the last element of linked list\n");
		printf("7.Delete the element from the inserted node index\n");
	    printf("8.Display the elements of linked list\n");
		printf("9.Exit\n");
	do{
		printf("\n\nENTER YOUR CHOICE  :   ");
		scanf("%d",&choice);
	switch(choice)
		{
		case 1:
				printf("\nEnter the data to be inserted in linked list  :  ");
				scanf("%d",&data);
				create_list(&last,data);
			break;
		case 2:
			Insert_at_front(&last);
			break;
		case 3:
			Add_after(&last);
			break;
		case 4:
			Add_last(&last);
			break;
		case 5:
			Delete_first(&last);
			break;
	    case 6:
	    	Delete_last(&last);
	    	break;
	    case 7:
	    	Delete_atindex(&last);
	    	break;
		case 8:
			display(&last);
			break;
		case 9:
			printf("Exiting the program.......................................");
			break;
		default:
		 	printf("WRONG CHOICE!!!!!!!");
		}
	}while(choice!=9);
	return 0;
}//End of Circular Linked list program 
