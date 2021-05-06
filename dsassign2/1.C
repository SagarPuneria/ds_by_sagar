#include<iostream>
using namespace std;
template<class T>
class search
{
	int size;
	T *a;
	public:
	search()
	{	
		size=0;
		a=NULL;
	}
	search(int n)
	{
		a=new T[n];
		size=n;
	}	
	void get_data()
	{                                                                                                  
		int i;
		for(i=0;i<size;i++)		
			cin>>a[i];
	}
	T b_s(T k)
	{
		T m;
		int l=0,h=size;
		while(l<=h)
		{
			m=(l+h)/2;
			if(a[m]==k)
				return m;
			if(a[m]<k)
				l=m+1;
			if(a[m]>k)
				h=m-1;
		}
		return(-1);
	}
	T l_s(T k)
	{
		int i;
		for(i=0;i<size;i++)
			if(k==a[i])
				return i;
		return -1;
	}
	~search()
	{
		cout<<"inside destructor\n";
		delete a;
	}
};
int main()
{
	search<char>s(6);
	char k;
	int res;
	s.get_data();
	cout<<"Enter key value for binary search \n";
	cin>>k;
	res=s.b_s(k);
	if(res==-1)
		cout<<"element not found\n";
	else
		cout<<"element is "<<k<<" found at location of "<<res<<endl;
	cout<<"Enter key value for linear search \n";
	cin>>k;
	res=s.l_s(k);
	if(res==-1)
		cout<<"element not found\n";
	else
		cout<<"element is "<<k<<" found at location of "<<res<<endl;
	return 0;
} 
