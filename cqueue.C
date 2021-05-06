#include<iostream>
#include<stdlib.h>
using namespace std;
class cque
{
	int f;
	int r;
	int size;
	int *a;
public:
	cque()
	{
		f=r=-1;
		size=0;
		a=NULL;
	}
	cque(int n)
	{
		size=n;
		r=f=-1;
		a=new int[n];
	}
	bool underflow()
	{
		return ((r+1)%size==f);
	}
	bool overflow()
	{
		return (r+1==size);
	}
	void enq(int p)
	{
		if((f==0 && r==size-1) || (f==(r+1)%size))//(or)//if((f==0 && r==size-1) || (f==r+1))
		{
	  		cout<<"overflow\n";
   	  		return;
	 	}
	 	if(f==-1 && r==-1)
	 		f++;
	 	r=(r+1)%size;
		a[r]=p;
		cout<<"inserted element is "<<a[r]<<endl; 
	}
	int deq()
	{
		int x=-999;
		if(f==-1 || (f==(r+1)%size))//(or)if(f==-1 || f==r+1)
		{
			cout<<"under flow\n";
			return x;
		}		
		x=a[f];
		if(f==r)
			f=r=-1;
		else
			f=(f+1)%size;
		return x;
	} 
	void display()
	{
		int i;
		//cout<<f <<r <<endl;
		if(f==-1 || f==r+1)//(or)if(f==-1 || f==r+1)
		{
			cout<<"under flow\n";
			return;
		}
		cout<<"queue elements are\n";
		if(f<=r)
		{
			for(i=f;i<=r;i++)
				cout<<a[i]<<endl;
		}
		else
		{
			for(i=f;i<=size-1;i++)
				cout<<a[i]<<endl;
			for(i=0;i<=r;i++)
				cout<<a[i]<<endl;
		}
	}
	~cque()
	{
		cout<<"inside destructor\n";
		delete a;
	}
};
int main()
{	cque q1(5);
	int x,ch,ele;
	while(1)
	{
		cout<<"1.Inssert\n";
		cout<<"2.delete\n";
		cout<<"3.display\n";
		cout<<"4.quit\n";
		cout<<"Enter your choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<"enter ele for adding in queue\n";
				cin>>ele;
				q1.enq(ele);
				break;
			case 2:x=q1.deq();
				cout<<"deleted ele in queue "<<x<<endl;
				break;
			case 3:q1.display();
				break;
			case 4:exit(1);
			default:cout<<"wring choice\n";
		}
	}
	/*
	for(i=0;i<6;i++)
	{	cin>>j;
		q1.enq(j);
	}
	/*q1.enq(5);
	q1.enq(10);
	i=q1.deq();
	cout<<"deleted ele is "<<i<<endl;
	q1.display();
	i=q1.deq();
	cout<<"deleted ele is "<<i<<endl;
	
	q1.display();*/
	return 0;
}
