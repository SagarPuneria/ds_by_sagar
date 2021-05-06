#include<iostream>
using namespace std;
class matrix
{
	int **a;
	int r;
	int c;
	public:
	matrix();
	matrix(int,int);
	/*void read_matrix();
	void print_matrix();
	matrix operator-(matrix m2)
	{
		matrix m3;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				m3.a[i][j]=a[i][j]-m2.a[i][j];
		return m3;
	}
	friend matrix operator+(matrix,matrix);
	friend matrix operator+(int,matrix);
	matrix operator+(int x)
	{
		matrix m;
		for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			m.a[i][j]=a[i][j]+x;
		return m;
	}*/
	friend ostream &operator<<(ostream &,matrix);
	friend istream &operator>>(istream &,matrix &);
	int sum();
};
int matrix::sum()
{	
	int sum1=0;
	 for(int i=0;i<r;i++)
                for(int j=0;j<c;j++)
                        if(i>j)
				sum1=sum1+a[i][j];
	return sum1;
}
matrix::matrix()
{
	r=2;
	c=2;
	a=new int *[r];
	for(int i=0;i<r;i++)
		*(a+i)=new int[c];
}
matrix::matrix(int x,int y)
{
	r=x;
	c=y;
	a=new int *[r];
	for(int i=0;i<r;i++)
		*(a+i)=new int[c];
}/*
matrix operator+(int x,matrix m)
{
	matrix t;
	for(int i=0;i<m.r;i++)
		for(int j=0;j<m.c;j++)
			t.a[i][j]=m.a[i][j]+x;
	return t;
}
void matrix::read_matrix()
{
	int i,j;
	cout<<"input elements of matrix\n";
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			cin>>*(*(a+i)+j);
}
void matrix::print_matrix()
{
	cout<<"elements of matrix are\n";
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			cout<<*(*(a+i)+j)<<"\t";
		cout<<endl;
	}
}
matrix operator+(matrix m1,matrix m2)
{
	matrix m3;
	for(int i=0;i<m1.r;i++)
		for(int j=0;j<m2.c;j++)
			m3.a[i][j]=m1.a[i][j]+m2.a[i][j];
	return m3;
}*/
ostream &operator<<(ostream &cout,matrix m)
{
	cout<<"elements of matrix are\n";
	for(int i=0;i<m.r;i++)
	{
		for(int j=0;j<m.c;j++)
			cout<<m.a[i][j]<<"\t";//*(*(a+i)+j)<<"\t";
		cout<<endl;
	}
	return cout;
}
istream &operator>>(istream &cin,matrix &m)
{
	cout<<"input elements of matrix\n";
	for(int i=0;i<m.r;i++)
		for(int j=0;j<m.c;j++)
			cin>>m.a[i][j];
	return cin;
}
int main()
{
	int sum1=0;
	matrix m2(3,3);
	cin>>m2;
	cout<<m2;
	sum1=m2.sum();
	cout<<"sum="<<sum1<<endl;/*
	matrix m1,m2(3,3),m3;
	m1.read_matrix();
	m1.print_matrix();
	m2.read_matrix();
	m2.print_matrix();
	m3=m1+m2;
	m3.print_matrix();
	m3=m1-m2;
	m3.print_matrix();
	m3=m1+3;
	m3.print_matrix();
	m3=4+m2;
	m3.print_matrix();
	cout<<m3;
	cin>>m3;
	m3.print_matrix();*/
	return 0;
}
