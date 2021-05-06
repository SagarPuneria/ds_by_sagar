#include<iostream>
using namespace std;
template<class u>
class mer
{
	u *a,*b;
	int size;
public:
	void get_data()
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
	mer()
	{
		a=NULL;
		size=0;
	}
	mer(int n)
	{
		size=n;
		a=new u[size];
		b=new u[size];
	}
	~mer()
	{
		cout<<"inside destructor\n";
		delete a;
		delete b;
	}
	void merge_s(int l,int h)
	{
		int m;
		if(l<h)
		{
			m=(l+h)/2;
			merge_s(l,m);
			merge_s(m+1,h);
			merge(l,m,h);
		}
	}
	void merge(int l,int m,int h)
	{
		int i,j,k,p;
		//u b[50];
		i=l;j=m+1;k=l;
		while((i<=m) && (j<=h))
		{
			if(a[i]<=a[j])
				b[k++]=a[i++];
			else
				b[k++]=a[j++];
		}
		while(i<=m)
			b[k++]=a[i++];
		while(j<=h)
			b[k++]=a[j++];
		for(p=0;p<=h;p++)
			a[p]=b[p];
	}
};
int main()
{
	int s;
	cout<<"enter size of array\n";
	cin>>s; 
	mer<char>m(s);
	cout<<"enter elements\n";
	m.get_data();
	cout<<"Before sorting\n";
	m.display();
	m.merge_s(0,s-1);
	cout<<"After sorting\n";
	m.display();
	return 0;
}
