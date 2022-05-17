#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node *next;
	node(int val)
	{
		data = val;
		next = NULL;
	}
};
void insert_at_tail(node * &head,int val)
{
	node *n = new node(val);
	node *p = head;
	if(head==NULL)
	{
		head = n;
		return ;
	}
	
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next = n;
}
void display(node *head)
{
	node *p = head;
	while(p!=NULL)
	{
		cout<<p->data<<"-->";
		p = p->next;
	}
}
void insert_at_head(node * &head,int val)
{
	node *newnode = new node(val);
	if(head==NULL)
	{
		head = newnode;
		return;
	}
	newnode->next = head;
	head = newnode;
	
}
bool search(node *head,int key)
{
	int i = 0;
	while(head!=NULL)
	{
		if(head->data == key){
			cout<<"Key is found"<<"at "<<i<<"positio"<<endl;
			return true;
	}
	i++;
		head = head->next;
	}

	return false;
}
int main()
{
	node * head = NULL;
	insert_at_tail(head,1);
	insert_at_tail(head,2);
	insert_at_tail(head,3);
	insert_at_tail(head,4);
	insert_at_head(head,999);
	if(search(head,4))
		cout<<"Key is found";
	else
		cout<<"key not found";
		
	return 0;
	
}
