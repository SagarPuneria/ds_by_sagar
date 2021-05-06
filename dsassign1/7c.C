#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
class __stack__
{
	char *a;
	int tos;
	int size;
	int i;
	public:
		void push(char);
		char pop();
		char peek();
		bool Isfull();
		bool Isempty();
		__stack__();
		__stack__(int);
		~__stack__();
/*		void display()
		{
			if(tos==-1)
			cout<<"stack is empty";
			else
			for(i=0;i<=tos;i++)
			cout<<"stack elements are "<<a[i]<<endl;
			cout<<"\n";
		}*/
};
__stack__::__stack__()
{
	a=NULL;
	tos=-1;
	size=0;
}
__stack__::__stack__(int n)
{
	a = new char[n];
	tos=-1;
	size=n;
}
bool __stack__::Isempty()
{
	return (tos==-1);
}
bool __stack__::Isfull()
{
	return (tos+1>=size);
}
void __stack__::push(char element)
{
	if(!Isfull())
		a[++tos]=element;
	else
		cout<<"stack is full";


}
char __stack__::pop()
{
	char ch;
	if(!Isempty())
		ch=a[tos--];
	else
		cout<<"stack is empty";
	return ch;
}
char __stack__::peek()
{
	char ch;
	if(!Isempty())
		ch=a[tos];
	else
		cout<<"stack is empty";
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
int prec(char);
int main()
{
	__stack__ s1(10);
	char ostr[30];
	char str[]="a+b*c+(d*e+f)*g";//"(a+b*c+g*h)";
	int flag=0,i,j=0;
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
				ch=s1.pop();
				while(!(ch=='('||ch=='['||ch=='{'))
				{	
					ostr[j++]=ch;
					ch=s1.pop();
				}
				break;
			case '+':
			case '-':
			case '*':
			case '/':
				while(!s1.Isempty() && (prec(str[i])<=prec(s1.peek())))
					ostr[j++]=s1.pop();
				s1.push(str[i]);
				break;
			default:
				ostr[j++]=str[i];
		}//switch
	}//for
	while(!s1.Isempty())
		ostr[j++]=s1.pop();
	ostr[j]='\0';
	cout<<"postfix is "<<ostr<<endl;
	return 0;
}
int prec(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':return 1;
		case '*':
		case '/':return 2;
		case '(':
		case '{':
		case '[':return 0;
	//	default :;
	}
}
