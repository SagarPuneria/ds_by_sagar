#include<iostream>
using namespace std;
class stac
{
	int *a;
	int top;
	int size;
public:
	void push(int);
	int pop();
	int peek();
	//bool isfull();
	//bool isempty();
	stac()
	{
		a=NULL;
		top=-1;
		size=0;
	}
	stac(int n)
	{
		a=new int [n];
		top=-1;
		size=n;
	}
	void display()
	{
		int i;
		if(top==-1)//if(!(isempty()))
		{	
			cout<<"stack is empty";
			return;
		}
		cout<<"stack elements are\n";	
		for(i=top;i>=0;i--)
			cout<<a[i]<<endl;
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
	if(curr==NULL)//if(!(isfull()))
	{
		cout<<"stack is full\n";
		return;
	}
	top++;
	a[top]=ele;
	cout<<a[top]<<"\n";
}
int stac::pop()
{
	int x=-99;
	if(top==-1)//if(!(isempty()))
	{	
		cout<<"stack is empty";
		return x;
	}
	x=a[top];
	top--;
	cout<<"pop element is "<<x<<endl;;	
	return x;
}
int stac::peek()
{
	int x=-99;
	if(top==-1)//if(!(isempty()))
	{	
		cout<<"stack is empty";
		return x;
	}	
	return a[top];
}
int main()
{
	stac s1,s(4);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	s.push(7);
	s.pop();
	s.pop();
	s.display();
	cout<<"peek element is "<<s.peek()<<endl;
	return 0;
}	 
