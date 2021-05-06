#include<iostream>
using namespace std;
template<class u>
class bubble
{
	u *a;
	int size;
public:
	bubble()
	{
		a=NULL;
		size=0;
	}
	bubble(int n)
	{
		size=n;
		a=new u[size];
	}
	~bubble()
	{
		cout<<"inside destructor\n";
		delete a;
	}
	void read()
	{
		for(int i=0;i<size;i++)
			cin>>a[i];
	}	
	void display()
	{
		for(int i=0;i<size;i++)
			cout<<a[i]<<"\t";
		cout<<"\n";
	}
	void buble()
	{
		int i,j,flag=0,temp;
		for(i=0;i<size-1;i++)
		{
			flag=0;
			for(j=0;j<size-1-i;j++)
			{
				if(a[j]>a[j+1])
				{
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
					flag=1;
				}
			}
			if(flag==0)
				break;
		}
	}
};
int main()
{
	bubble<char>b(5);
	b.read();
	b.display();
	b.buble(); 
	b.display();
	return 0;
}	
