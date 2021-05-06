#include<iostream>
using namespace std;
template<class T>
class inser
{
	int size;
	T *a;
	public:
	inser()
	{	
		size=0;
		a=NULL;
	}
	inser(int n)
	{
		a=new T[n];
		size=n;
	}
	~inser()
	{	
		cout<<"inside destructor\n";
		delete a;
	}	
	void get_data()
	{                                                                                                  
		int i;
		for(i=0;i<size;i++)		
			cin>>a[i];
	}
	void insertion()
	{
		int i,j;
		T temp;
		for(i=1;i<size;i++)
		{
			for(j=i;j>0 && a[j-1]>a[j];j--)
			{
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
			}
		}
	}
	void display()
	{
		for(int i=0;i<size;i++)
			cout<<a[i]<<"\t";
		cout<<endl;
	}
};
int main()
{
	inser<char>s(6);
	s.get_data();
	cout<<"Before sorting\n";
	s.display();
	s.insertion();
	cout<<"After sorting\n";
	s.display();
	return 0;
}
