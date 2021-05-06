#include<iostream>
using namespace std;
template<class T>
class quick
{
	int size;
	T *a;
	public:
	quick()
	{	
		size=0;
		a=NULL;
	}
	quick(int n)
	{
		a=new T[n];
		size=n;
	}
	~quick()
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
	void quick_s(int low,int high)
	{
	T temp;//i,j,pivot;
	T pivot=a[low];
	int i=low+1;
	int j=high;
	if(low<high)
	{
		while(i<=j)
		{
			while(a[i]<pivot)
				i++;
			while(a[j]>pivot)
				j--;
			if(i<j)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
			else
				break;
		}
		temp=a[low];
		a[low]=a[j];
		a[j]=temp;
		quick_s(low,j-1);
		quick_s(j+1,high);
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
	int s;
	cout<<"enter size of array\n";
	cin>>s; 
	quick<int>q(s);
	cout<<"enter elements\n";
	q.get_data();
	cout<<"Before sorting\n";
	q.display();
	q.quick_s(0,s-1);
	cout<<"After sorting\n";
	q.display();
	return 0;
}
