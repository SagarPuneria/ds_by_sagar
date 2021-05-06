#include<iostream>
#include<stdlib.h>
using namespace std;
class queue
{
	int f,r;
	int *a;
	int size;
	public:
	void enque(int);
	int deque();
	//bool underflow();
	//bool overflow();
	void display();
	queue();
	queue(int );
	~queue();
};
queue::queue()
{
	size=0;
	f=r=-1;
	a=NULL;
}
queue::queue(int n)
{
	size=n;
	a=new int[n];
	f=r=-1;
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
	
	if(r==size-1)//if(!overflow())
	{
	//cout<<f <<r <<endl;
		cout<<"overflow\n";
		return;
	}
	if(f==-1 && r==-1)
		f=0;
	a[++r]=ele;
	cout<<"inserted element is "<<a[r]<<endl; 
}
void queue::display()
{
	for(int i=f;i<=r;i++)
		cout<<a[i];
	cout<<endl;
}
int queue::deque()
{
	int x=-999;
	//if((f==-1 && r==-1) || (f=r+1))//if(!underflow())
	if(f==-1 && r==-1)
	{
		cout<<"underflow\n";
		return x;
	}
	x=a[f];
	if(f==r)
		f=r=-1;
	else
		f++;
	return x;
}
queue::~queue()
{
	cout<<"inside destructor\n";
	delete a;
}
int main()
{
	queue s(4);
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
			default:cout<<"wring choice\n";
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
