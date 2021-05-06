#include<iostream>
using namespace std;
template<class u>
class mer
{
	u *a,*b,*c;
	int size;
public:
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
		c=new u[2*size];
	}
	~mer()
	{
		cout<<"inside destructor\n";
		delete a;
		delete b;
	}
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
	void displaymerg()
	{
		int i;
		for(i=0;i<2*size;i++)
			cout<<c[i]<<"\t";
		cout<<endl;
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
	void merge_l(mer l1,mer l2)
	{
		int i=0,j=0;
		while(l1.a[i]!=0 && l2.a[j]!=0)
		{
			if(l1.a[i]<l2.a[j])
			{
				insert_s(l1.a[i]);
				i++;				
			}
			else if(l1.a[i]>l2.a[j])
			{
				insert_s(l2.a[j]);
				j++;
			}
			else if(l1.a[i]==l2.a[j])
			{
				insert_s(l1.a[i]);
				i++;
				j++;
			}
		}
		while(l1.a[i]!=0)
		{
			insert_s(l1.a[i]);
			i++;
		}
		while(l2.a[j]!=0)
		{
			insert_s(l2.a[j]);
			j++;
		}
	}
	void insert_s(int ele)
	{
		int i;
		for(i=0;c[i]!=0;i++)
		;
		c[i]=ele;
		
	}
};
int main()
{
	int s;
	cout<<"enter size of array\n";
	cin>>s; 
	mer<int>m1(s),m2(s),m3(s);

	cout<<"enter elements for array 1\n";
	m1.get_data();
	cout<<"enter elements for array 2\n";
	m2.get_data();

	cout<<"Before sorting array 1\n";
	m1.display();
	cout<<"Before sorting array 2\n";
	m2.display();

	m1.merge_s(0,s-1);
	cout<<"After sorting array 1\n";
	m1.display();

	m2.merge_s(0,s-1);
	cout<<"After sorting array 2\n";
	m2.display();

	m3.merge_l(m1,m2);
	cout<<"After merging two sorting array\n";
	m3.displaymerg();
	return 0;
}
