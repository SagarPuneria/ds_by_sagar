#include<iostream>
#include<string.h>
using namespace std;
template<class T>
class ins
{
	T *a;
	int size;
	public:
	ins()
	{
		a=NULL;
		size=0;
	}
	ins(int n)
	{
		a=new T[n];
		size=n;
	}
	void get()
	{
		int i;
		cout<<"enter elements\n";
		for(i=0;i<size;i++)
			cin>>a[i];
	}
	void print()
	{
		int i;
		cout<<"After sorting elements are\n";
		for(i=0;i<size;i++)
			cout<<a[i]<<"\t";
		cout<<"\n";
	}
	void insert_s();
};
template<>
void ins<char *>::get()
{
	
	int i;
	char str[15],ch;
	
	for(i=0;i<size;i++)
	{
		cout<<"enter a string\n";
		cin>>str;
		a[i]=new char[strlen(str)+1];
		strcpy(a[i],str);
	}
}
template<>
void ins<char *>::insert_s()
{
	int i,j,n1,n2;
	char *temp;
	for(i=1;i<size;i++)//logic for insertion sort
	{
		for(j=i;j>0;j--)
		{
			n1=*a[j-1];
			n2=*a[j];
			if(n1>n2)
			{
			temp=new char[strlen(a[j-1])+strlen(a[j])+1];
			strcpy(temp,a[j-1]);
			strcpy(a[j-1],a[j]);
			strcpy(a[j],temp);
			}
		}
	}
}

		
template<class T>
void ins<T>::insert_s()
{
	int i,j;
	T temp;
	for(i=1;i<size;i++)//logic for insertion sort
	{
		for(j=i;j>0 && a[j-1]>a[j];j--)
		{
			temp=a[j-1];
			a[j-1]=a[j];
			a[j]=temp;
		}
	}
}
int main()
{
	ins<char>n(4);
	n.get();
	n.insert_s();
	n.print();
	ins<char>c(4);
	c.get();
	c.insert_s();
	c.print();
	ins<char *>s(3);
	s.get();
	s.insert_s();
	s.print();
	return 0;
}
