#include<iostream>
#include<stdlib.h>
using namespace std;
class queue
{
	struct node 
	{
		int data;
		struct node *next;
	};
	struct node *front,*rear;
	public:
	void enque(int);
	int deque();
	//bool underflow();
	//bool overflow();
	void display();
	queue();
	//queue(int );
	~queue();
};
queue::queue()
{
	front=rear=NULL;
}
/*bool queue::underflow()
{
	return((f==-1)&&(r==-1));
}
bool queue::overflow()
{
	return(r+1==size);
}*/
void queue::enque(int ele)
{
	struct node *temp;
	temp=new node;
	if(front==temp)//if(temp==NULL)//if(!(isfull()))
	{
		cout<<"memory is not available\n";
		return;
	}
	temp->data=ele;
	temp->next=NULL;
	if(front==NULL)//queue is empty
		front=temp;
	else
		rear->next=temp;
	rear=temp;
	cout<<"inserted element is "<<temp->data<<endl; 
}
void queue::display()
{
	struct node *curr;
	if(front==NULL && rear==NULL)
	{	
		cout<<"stack is empty\n";
		return;
	}
	cout<<"queue elements are\n";	
	for(curr=front;curr!=NULL;curr=curr->next)
		cout<<curr->data<<"\t";
	cout<<endl;
}
int queue::deque()
{
	int x=-999;
	//if((f==-1 && r==-1) || (f=r+1))//if(!underflow())
	struct node *temp;
	if(front==NULL && rear==NULL)
	{
		cout<<"underflow\n";
		return x;
	}
	temp=front;
	x=front->data;
	front=front->next;
	delete temp;
	return x;
}
queue::~queue()
{
	struct node *curr;
	while(front!=NULL)
	{
		curr=front->next;
		delete front;
		front=curr;
	}
	cout<<"inside destructor\n";
}
int main()
{
	queue s;
	int x,ch,ele,flag=0;
	while(1)
	{
		cout<<"1.Insert\n";
		cout<<"2.delete\n";
		cout<<"3.display\n";
		cout<<"4.quit\n";
		cout<<"Enter your choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<"enter ele for adding in queue\n";
				cin>>ele;
				s.enque(ele);
				break;
			case 2:x=s.deque();
				cout<<"deleted ele in queue "<<x<<endl;
				break;
			case 3:s.display();
				break;
			case 4:flag=1;//exit(1);
				break;
			default:cout<<"wrong choice\n";
		}
		if(flag==1)
			break;
	}
/*	s.enque(1);
	s.enque(2);
	s.enque(3);
	s.enque(4);
	s.enque(5);
	x=s.deque();
	cout<<x<<endl;
	s.display();
	s.enque(6);
	//s.enque(7);
	//s.display();*/
	return 0;
}
