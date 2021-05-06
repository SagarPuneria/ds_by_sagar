#include<iostream>
#include<stdlib.h>
using namespace std;
class deque
{
	struct node
	{
		int data;
		struct node *next,*prev;
	};
	struct node *head;
	//protected:
	public:
	//struct node *head;
	void insertbeg(int);
	void insertend(int);
	int del_first();
	//int del_last();
	deque()
	{
		head=NULL;
	}
	~deque()
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
	void display()
	{
		if(head==NULL)
		{
			cout<<"list is empty\n";
			return;
		}
		struct node *curr;
		curr=head;
		cout<<"list is\n";
		while(curr!=NULL)
		{
			cout<<curr->data<<"\t";
			curr=curr->next;
		}
		cout<<endl;
	}

};
void deque::insertbeg(int ele)
{
	struct node *temp;
	temp=new node;
	temp->data=ele;
	temp->prev=NULL;
	temp->next=head;
	if(head!=NULL)
		head->prev=temp;
	head=temp;
}
void deque::insertend(int ele)
{
	struct node *temp,*curr;
	temp=new node;
	temp->data=ele;
	temp->next=NULL;
	if(head==NULL)
	{
		temp->prev=NULL;
		head=temp;
		return;
	}
	curr=head;
	while(curr->next!=NULL)
		curr=curr->next;
	temp->prev=curr;
	curr->next=temp;
}
int deque::del_first()
{
	int x=-99;
	if(head==NULL)
	{
		cout<<"list is empty\n";
		return x;
	}
	struct node *temp;
	temp=head;
	if(head->next!=NULL)//if it is not only node
	{
		head=head->next;
		head->prev=NULL;
	}	
	else
		head=NULL;
	x=temp->data;
	delete temp;
	return x;
}	
/*int deque::del_last()
{
	int x=-99;
	if(head==NULL)
	{
		cout<<"list is empty\n";
		return x;
	}
	struct node *curr;
	curr=head;
	if(head->next!=NULL)
	{
		while(curr->next!=NULL)
			curr=curr->next;
		curr->prev->next=NULL;
	}
	else
		head=NULL;
	x=curr->data;
	delete curr;
	return x;
}*/
class stack:public deque
{
	public:
	void push(int ele)
	{
		insertbeg(ele);//this->insertbeg(ele);
	}
	int pop()
	{
		return del_first();
	}
};
class queue:public deque
{
	public:
	void enqueue(int ele)
	{
		insertend(ele);//this->insertend(ele);
	}
	int dequeue()
	{
		return del_first();
	}
	//int del_last;
};
int main()
{
	stack s;
	queue q;
	int ch,ele,sea,item,flag=0;
	while(1)
	{
		cout<<"1.display for stack\n";
		cout<<"2.display for queue\n";
		cout<<"3.enqueue element\n";
		cout<<"4.dequeue element\n";
		cout<<"5.push element\n";
		cout<<"6.pop element\n";
		cout<<"7.quit\n";
		cout<<"Enter your choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1:s.display();
				break;
			case 2:q.display();
				break;
			case 3:cout<<"enqueue element in queue\n";
				cin>>ele;
				q.enqueue(ele);//(or)s.insertend(ele);
				break;	
			case 4:cout<<"dequeue element in queue "<<q.dequeue()<<endl;//(or)q.del_first;
				break;
			case 5:cout<<"push element in stack\n";
				cin>>ele;
				s.push(ele);//(or)s.insertbeg(ele);
				break;
			case 6:cout<<"poped element in stack "<<s.pop()<<endl;//(or)q.del_first;
				break;
			//case 5:cout<<"deleted element at end "<<q.del_last()<<endl;//(or)q.del_last();
			//	break;
			case 7:flag=1;
				break;
			default:cout<<"wrong choice\n";
		}
		if(flag==1)
			break;
	}	
	return 0;
}
