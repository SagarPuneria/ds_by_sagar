#include<iostream>
#include<stdlib.h>
using namespace std;
class stac
{
	struct node 
	{
		int data;
		struct node *next;
	};
	struct node *top;
public:
	void push(int);
	int pop();
	int peek();
	//bool isfull();
	//bool isempty();
	stac()
	{
		top=NULL;
	}
	~stac()
	{
		struct node *curr;
		while(top!=NULL)
		{
			curr=top->next;
			delete top;
			top=curr;
		}
		cout<<"inside destructor\n";
	}
	void display()
	{
		struct node *curr;
		if(top==NULL)
		{	
			cout<<"stack is empty\n";
			return;
		}
		cout<<"stack elements are\n";	
		for(curr=top;curr!=NULL;curr=curr->next)
			cout<<curr->data<<endl;
	}
};
/*bool stac::isempty()
{
	return(top==-1);
}
bool stac::isfull()
{
	return(top>=size);
}*/
void stac::push(int ele)
{
	struct node *curr;
	curr=new node;
	if(curr==NULL)//if(!(isfull()))
	{
		cout<<"stack overflow\n";
		return;
	}
	curr->data=ele;
	curr->next=top;
	top=curr;
}
int stac::pop()
{
	struct node *curr;
	int x=-99;
	if(top==NULL)//if(!(isempty()))
	{
		cout<<"stack is empty";
		return x;
	}
	curr=top;
	x=curr->data;
	top=curr->next;
	delete curr;
	return x;
}
int stac::peek()
{
	int x=-99;
	if(top==NULL)//if(!(isempty()))
	{	
		cout<<"stack is empty";
		return x;
	}	
	return top->data;
}
int main()
{
	stac s;
	int x,ch,ele,flag=0;
	while(1)
	{
		cout<<"1.push\n";
		cout<<"2.pop\n";
		cout<<"3.pop\n";
		cout<<"4.display\n";
		cout<<"5.quit\n";
		cout<<"Enter your choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<"push ele in stack\n";
				cin>>ele;
				s.push(ele);
				break;
			case 2:x=s.pop();
				cout<<"poped ele in stack "<<x<<endl;
				break;
			case 3:x=s.peek();
				cout<<"peek ele in stack "<<x<<endl;
				break;
			case 4:s.display();
				break;
			case 5:flag=1;
				break;//exit(1);
			default:cout<<"wrong choice\n";
		}
		if(flag==1)
			break;
	}
	/*s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	s.push(7);
	s.display();
	cout<<"poped element is "<<s.pop()<<"\n";
	cout<<"poped element is "<<s.pop()<<"\n";
	s.display();
	cout<<"peek element is "<<s.peek()<<endl;*/
	return 0;
}	 
