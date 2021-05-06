#include<iostream>
using namespace std;
template<class T>
class heap
{
	int size;
	T *a;
	public:
	heap()
	{	
		size=0;
		a=NULL;
	}
	heap(int n)
	{
		a=new T[n];
		size=n;
	}
	~heap()
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
	void display()
	{
		for(int i=0;i<size;i++)
			cout<<a[i]<<"\t";
		cout<<endl;
	}
	void heap_s(int n)
	{
		T temp;
		int i,j;
		for(i=(n/2)-1;i>=0;i--)
			heapify(i,n);
		for(j=n-1;j>0;j--)
		{
			temp=a[0];
			a[0]=a[j];
			a[j]=temp;
			heapify(0,j);
		}
	}
	void heapify(int i,int n)
	{
		T temp;
		int c;
		for(temp=a[i];2*i+1<n;i=c)
		{
			c=2*i+1;
			if(c+1<n && a[c+1]>a[c])
				c++;
			if(temp<a[c])
				a[i]=a[c];
			else
				break;
		}
		a[i]=temp;
	}
};
int main()
{
	int s;
	cout<<"enter size of array\n";
	cin>>s; 
	heap<char>h(s);
	cout<<"enter elements\n";
	h.get_data();
	cout<<"Before sorting\n";
	h.display();
	h.heap_s(s);
	cout<<"After sorting\n";
	h.display();
	return 0;
}
