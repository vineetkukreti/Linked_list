#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node *next;
		node(int value)
		{
			data = value;
			next = NULL;
		}
};

void create_node(node * &head,int value)
{
	node *new_node = new node(value);
	if(head==NULL)
	{
		head = new_node;
		return ;
	}
	node *p = head;
	while(p->next!=NULL)
	{
		p = p->next;
	}
	p->next = new_node;
}
void display(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	
}
void delete_node_first(node * &head)
{
	if(head==NULL)
	{
		cout<<"Linked list is empty";
		return ;
	}
	else
	{
		node *p = head;
		head = head->next;
		delete p;
	}
}

void delete_node_last(node * &head)
{
	if(head==NULL)
	{
		cout<<"Linked list is empty";
		return ;
	}
	else
	{
		node *p = head->next;
		node *q;
	    while(p->next!=NULL)
	    {
	    	q = p;
	    	p = p->next;
		}
		q->next = NULL;
		delete p;
	}
}
void delete_node_inBetween(node *head,int val)
	{
		if(head==NULL)
		{
			cout<<"Linked list is empty";
			return ;
		}
		else
		{
			node *p = head,*s = head,*q;
			while(s!=NULL)
			{   
				q = p;
				p=p->next;
				if(p->data==val)
				{
					q->next = p->next;
					delete p;
					return;
				}
				s=s->next;
			}
		}
	}


int main()
{
	node *head = NULL;
	create_node(head,12);
	create_node(head,5);
	create_node(head,28);
	create_node(head,9);
	create_node(head,112);
	create_node(head,1102);
	//delete_node_first(head);
	//delete_node_last(head);
	delete_node_inBetween(head,112);
	display(head);
	return 0;
}
