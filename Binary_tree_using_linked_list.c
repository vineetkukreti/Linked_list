#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

void Insert(struct node **root,int data)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	struct node *current;
	struct node *parent;
	
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	if(*root==NULL)
	{
		*root=temp;
	}
	else
	{
		current=*root;
		parent=NULL;
		while(1)
		{
			parent=current;
			if(data<parent->data)
			{
				current=current->left;
				if(current==NULL)
				{
					parent->left=temp;
					return;
				}
			}
			else if(data>parent->data)
			{
				current=current->right;
				if(current==NULL)
				{
					parent->right=temp;
					return;
				}
			}
			else
			{
				printf("\nDuplicate node Entered!!!!!!\n");
				return;
			}
		}  
	}
}

//Searching Function
void Search(struct node *root)
{
	int data;
	printf("\nEnter the value for checking : ");
	scanf("%d",&data);
	struct node *temp=root;
	while(temp->data!=data)
	{
		if(data<temp->data)
		   temp=temp->left;
		else
		   temp=temp->right;
		if(temp==NULL)
		{
			printf("\nElement not found!!!\n");
			return;
		}
	}
	if(temp->data==data)
	  printf("\nElement found\n");
}
//Preorder Transversal
void Preorder(struct node *root)
{
	if(root!=NULL)
	{
		printf("\n%d\n",root->data);
		Preorder(root->left);
		Preorder(root->right);
	}
}

//Inorder Transversal
void Inorder(struct node *root)
{
	if(root!=NULL)
	{
		Inorder(root->left);
		printf("\n%d\n",root->data);
		Inorder(root->right);
	}
}

//Postorder Transversal
void Postorder(struct node *root)
{
	if(root!=NULL)
	{
		Postorder(root->left);
		Postorder(root->right);
		printf("\n%d\n",root->data);
	}
}
//Find max Function
//find max(struct node *n)
//{
//	while(n->data>)
//}
//Delete Function
void Delete(struct node **root,data)
{
	
	struct node *temp;
	if(*root==NULL)
	   ("\nNo such Element Found\n");
	else if(data>(*root)->data)
	    (*root)->left=Delete((*root)->left,data);
	else if(data<(*root)->data)
	     (*root)->right=Delete((*root)->right,data);
	else
	{
		if((*root)->left&&(*root)->right)
		{
			temp=Findmax((*root)->left);
			(*root)->data=temp->data;
			(*root)->left=Delete((*root)->left,(*root)->data);
		}
		else
		{
			temp=root;
			if((*root)->left==NULL)
			   *root=(*root)->right;
			if((*root)->right==NULL)
			   *root=(*root)->left;
			free(temp);
		}
	}
}

//Driver Program
int main()
{
	int choice,data;
	struct node *root=NULL;
	printf("			**********************\n			*********MENU*********\n			**********************\n");
	printf("			1.Insert\n");
	printf("			2.Search\n");
	printf("			3.Preorder Transversal\n");
	printf("			4.Inorder Transversal\n");
	printf("			5.Postorder Transversal\n");
	printf("			6.Exit\n");
	do
	{
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter data : ");
				scanf("%d",&data);
				Insert(&root,data);
				break;
			case 2:
				Search(root);
				break;
			case 3:
				Preorder(root);
				break;
			case 4:
				Inorder(root);
				break;
			case 5:
				Postorder(root);
				break;
			case 6:
				printf("\nEnter the data for deletion : ");
				scanf("%d",&data);
				Delete(root);
				break
			case 7:
				printf("\nExiting the program................................................\n");
				break;
			;
			default:
				printf("\nWRONG CHOICE!!!!!\n");
		}
	}while(choice!=7);
	return 0;
}