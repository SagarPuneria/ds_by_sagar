#include<iostream>
#include<string.h>
using namespace std;
//char x[15]="empty";
class deque
{
	struct node
	{
		char *data;
		struct node *next,*prev;
	};
	struct node *head;
	public:
	void insertbeg(char []);
	void insertend(char []);
	char *del_first();
	char *search(char []);
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
void deque::insertbeg(char ele[])
{
	struct node *temp;
	temp=new node;
	temp->data=new char[strlen(ele)+1];
	strcpy(temp->data,ele);
	temp->prev=NULL;
	temp->next=head;
	if(head!=NULL)
		head->prev=temp;
	head=temp;
}
char *deque::search(char item[])
{
	struct node *curr=head;
	while(curr!=NULL)
	{
		if(strcmp(curr->data,item)==0)
		{
			cout<<"bike is found\n";
			return item;
		}
		curr=curr->next;
	}
	cout<<"Bike not found\n";
}
void deque::insertend(char ele[])
{
	struct node *temp,*curr;
	temp=new node;
	temp->data=new char[strlen(ele)+1]; 
	strcpy(temp->data,ele);
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
char x[15]={0};
char *deque::del_first()
{
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
	strcpy(x,temp->data);
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
	void push(char ele[])
	{
		insertbeg(ele);//this->insertbeg(ele);
	}
	/*int pop()
	{
		return del_first();
	}*/
};
class queue:public deque
{
	public:
	void enqueue(char ele[])
	{
		insertend(ele);//this->insertend(ele);
	}
	char *dequeue()
	{
		return del_first();
	}
	//int del_last;
};
int main()
{
	deque d;
	stack s;
	queue q;
	char ele[15],sea[15],item[15];
	int ch,flag=0;
	while(1)
	{
		cout<<"1.Add a bike\n";
		cout<<"2.Book a bike(Reqeust)\n";
		cout<<"3.Map customer to bike\n";
		cout<<"4.Last sold bikes detail\n";
		cout<<"5.quit\n";
		cout<<"Enter your choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<"Add bike in queue\n";
				cin>>ele;
				d.insertbeg(ele);
				break;	
			case 2:cout<<"Enter request\n";
				cin>>sea;
				strcpy(item,d.search(sea));
				if(strcmp(item,sea)==0)
				{
					q.enqueue(item);
				}
				break;
			case 3:strcpy(item,q.dequeue());
				s.push(item);
				break;
			case 4:s.display();
				break;
			case 5:flag=1;
				break;
			default:cout<<"wrong choice\n";
		}
		if(flag==1)
			break;
	}	
	return 0;
}
