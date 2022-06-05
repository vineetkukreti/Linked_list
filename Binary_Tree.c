//Binary tree using recursion
//with global root pointer
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node node;
node *root=NULL;
node *insert(node *p,long digit,int *count)
{
	if(p==NULL)
	{
		p=(node*)malloc(sizeof(node));
		p->left=p->right=NULL;
		p->data=digit;
		(*count)++;
	}
	else if(digit<p->data)
	  p->left=insert(p->left,digit,&(*count));
	else if(digit>p->data)
	  p->right=insert(p->right,digit,&(*count));
	else{
		if(digit==p->data)
		{
			puts("Duplicate node : Program Exit");
			exit(0);
		}
	}
	return (p);
}
//node *insert(node *p,long digit,int *count)
//{
//	if(p==NULL)
//	{
//		p=(node*)malloc(sizeof(node));
//		p->left=p->right=NULL;
//		p->data=digit;
//		(*count)++;
//	}
//	else if(*count%2==0)
//	  p->left=insert(p->left,digit,&(*count));
//	else
//	  p->right=insert(p->right,digit,&(*count));
//	  
//	return (p);
//}
void search(node *p,int key)
{
	
	if(p==NULL)
	  printf("\n\nElement not found in Tree!!!!!\n\n");
	else if(p->data==key)
	{
		printf("\n%d found\n",p->data);
	}
	else if(key<p->data)
	{
		search(p->left,key);
	}
	else
	{
		search(p->right,key);
	}
}
void preorder(node *p)
{
	if(p!=NULL)
	{
		printf("%d\n",p->data);
		preorder(p->left);
		preorder(p->right);
	}
}

void inorder(node *p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		printf("%d	",p->data);
		inorder(p->right);
	}
}

void postorder(node *p)
{
	if(p!=NULL)
	{
		postorder(p->left);
		postorder(p->right);
		printf("%d	",p->data);	
	}
}
int main()
{
	int choice,count=1,key;
	long digit;
	printf("	*******MENU*******	\n");
	printf("\n1.Insert a node into Binary Tree\n2.Display(preorder)\n3.Display(inorder)\n4.Display(postorder)\n5.Search\n6.Exit\n\n");
	do
	{
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter the Digit : To quit Enter 0\n");
				scanf("%d",&digit);
				while(digit!=0)
				{
					root=insert(root,digit,&count);
					scanf("%d",&digit);
				}
				break;
			case 2:
				printf("\nPreorder Transversing Tree\n");
				preorder(root);
				break;
			case 3:
				printf("\nInorder Transversing Tree\n");
				inorder(root);
				break;
			case 4:
				printf("\nPostorder Transversing Tree\n");
				postorder(root);
				break;
			case 5:
				printf("\nEnter the element for searching : ");
				scanf("%d",&key);
				search(root,key);
				break;
			case 6:
				printf("\nExiting The Program ............................................\n");
		}
	}while(choice!=6);
}
