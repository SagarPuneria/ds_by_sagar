#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
class __stack__
{
	char *a;
	int top;
	int size;
//	int i;
	public:
		void push(char);
		char pop();
		char peek();
	//	bool Isfull();
		bool Isempty();
		__stack__();
		__stack__(int);
		~__stack__();
		void display()
		{
			if(top==-1)
			cout<<"stack is empty";
			else
			for(int i=0;i<=top;i++)
			cout<<"stack elements are "<<a[i]<<endl;
			cout<<"\n";
		}
};
__stack__::__stack__()
{
	a=NULL;
	top=-1;
	size=0;
}
__stack__::__stack__(int n)
{
	a = new char[n];
	top=-1;
	size=n;
}
bool __stack__::Isempty()
{
	return (top==-1);
}/*
bool __stack__::Isfull()
{
	return (tos>=size);
}*/
void __stack__::push(char ele)
{
	if(top>=size)//if(!(isfull()))
		cout<<"stack is full\n";
	else
	{
	top++;
	a[top]=ele;
	//cout<<a[top];
	return;
	}
}
char __stack__::pop()
{
	char ch;
	if(top==-1)//if(!(isempty()))
	cout<<"stack is empty";
	else
	{
	ch=a[top];
	top--;
	//cout<<"pop element is "<<ch<<endl;;	
	}
	return ch;
}
char __stack__::peek()
{
	char ch;
	if(top==-1)//if(!(isempty()))
	cout<<"stack is empty";
	else
	{
	ch=a[top];
	//cout<<"peek element is "<<ch<<endl;;	
	}
	return ch;
}
/*void __stack__::display()
{	//int i;
	if(tos==-1)
	cout<<"stack is empty"<<endl;
	else
	cout<<"stack elements are";
	for(i=0;i<=tos;i++)
		cout<<"the values in stack"<<a[i];

}*/
__stack__::~__stack__()
{
	delete a;
}

int main()
{
	__stack__ s1(26);
	char str[]="a+[b*c-(e*f)/[g+h*(i-j)]]";
	int flag=0,i;
	char ch;
	int n=strlen(str);
	for(i=0;i<n;i++)
	{
		switch(str[i])
		{
			case '(':
			case '[':
			case '{':
				s1.push(str[i]);
				break;
			case ')':
			case ']':
			case '}':
				ch=s1.peek();
				if((ch=='(' && str[i]==')') || (ch=='[' && str[i]==']') || (ch=='{' && str[i]=='}'))
				{	ch=s1.pop();
					cout<<"pop element is "<<ch<<endl;	
				//	flag=1
				}
				else 
					flag=1;
				break;
			default:break;
		}//switch
		if(flag==1)
			break;
	}//for
	if(i==n && s1.Isempty())
		cout<<"symbols are balanced\n";
	else
		cout<<"not balanced\n";
	return 0;
}
