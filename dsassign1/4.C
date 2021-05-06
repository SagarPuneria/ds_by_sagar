#include<iostream>
using namespace std;
class ml
{
	struct node 
	{
		int data;
		struct node *next;
	};
	struct node *head;
public:	
	ml()
	{
		head=NULL;
	}
	~ml()
	{
		struct node *curr;
		while(head!=NULL)
		{
			curr=head->next;
			delete head;
			head=curr;
		}
		cout<<"inside destructor\n";
	}
	void create_list()
	{
		int i,n,ele;
		cout<<"enter no. of nodes\n";
		cin>>n;
		if(n==0)
			return;
		for(i=1;i<=n;i++)
		{
			cout<<"enter ele to be inserted\n";
			cin>>ele;
			insert_s(ele);
		}
	}
	void insert_s(int ele)
	{
		struct node *curr,*temp;
		temp=new node;
		temp->data=ele;
		if(head==NULL || ele<head->data)
		{//if list is empty or data to be added in beginning
			temp->next=head;
			head=temp;
			return ;
		}
		curr=head;
		while(curr->next!=NULL && ele>curr->next->data)
			curr=curr->next;
		temp->next=curr->next;
		curr->next=temp;
	}
	void display()
	{
		struct node *curr;
		if(head==NULL)
		{
			cout<<"list is empty\n";
			return;
		}
		curr=head;
		while(curr!=NULL)
		{
			cout<<curr->data<<"\t";
			curr=curr->next;
		}
		cout<<"\n";
	}
	void merge(ml l1,ml l2)
	{
		struct node *c1,*c2;
		c1=l1.head;
		c2=l2.head;
		while(c1!=NULL && c2!=NULL)
		{
			if(c1->data<c2->data)
			{
				insert_s(c1->data);
				c1=c1->next;
			}
			else if(c1->data>c2->data)
			{
				insert_s(c2->data);
				c2=c2->next;
			}
			else if(c1->data==c2->data)
			{
				insert_s(c1->data);
				c1=c1->next;
				c2=c2->next;
			}
		}
		while(c1!=NULL)
		{
			insert_s(c1->data);
			c1=c1->next;
		}
		while(c2!=NULL)
		{
			insert_s(c2->data);
			c2=c2->next;
		}
		cout<<"merged list is\n";
		display();
	}
};
int main()
{
	ml l1,l2,l3;
	l1.create_list();
	l2.create_list();
	cout<<"list 1 is \n";
	l1.display();
	cout<<"list 2 is \n";
	l2.display();
	l3.merge(l1,l2);
}
