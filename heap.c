#include<stdio.h>
void heap_s(int b[],int n)
{
	int temp,i,j;
	for(i=(n/2)-1;i>=0;i--)
		heapify(b,i,n);
	for(j=n-1;j>0;j--)
	{
		temp=b[0];
		b[0]=b[j];
		b[j]=temp;
		heapify(b,0,j);
	}
}
void heapify(int a[],int i,int n)
{
	int temp,c;
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
int main()
{
	int i, a[13]={1,13,31,33,17,24,35,10,75,15,51,52,58};
	heap_s(a,13);
	for(i=0;i<13;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
