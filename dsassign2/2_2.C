#include<iostream>
using namespace std;
template<class u>
class sel
{
	u *a;
	int size;
public:
	void read()
	{
		for(int i=0;i<size;i++)
			cin>>a[i];
	}	
	void display()
	{
		for(int i=0;i<size;i++)
			cout<<a[i]<<"\t";
		cout<<endl;
	}
	sel()
	{
		a=NULL;
		size=0;
	}
	sel(int n)
	{
		size=n;
		a=new u[size];
	}
	~sel()
	{
		cout<<"inside destructor\n";
		delete a;
	}
	void selection()
	{
		u temp;
		int i,j,min;
		for(i=0;i<size-1;i++)
		{
			min=i;
			for(j=i+1;j<size;j++)
				if(a[min]>a[j])
					min=j;
			if(i!=min)
			{
				temp=a[i];
				a[i]=a[min];
				a[min]=temp;
			}
		}
	}	
};
int main()
{
	sel<char>s(6);
	s.read();
	cout<<"Before sorting\n";
	s.display();
	s.selection();
	cout<<"After sorting\n";
	s.display();
	return 0;
}
