#include<stdio.h>
void merge_s(int b[],int l,int h)
{
	int m;
	if(l<h)
	{
		m=(l+h)/2;
		merge_s(b,l,m);
		merge_s(b,m+1,h);
		merge(b,l,m,h);
	}
}
void merge(int a[],int l,int m,int h)
{
	int i,j,k,b[50],p;
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
int main()
{
	int i, a[12]={25,27,13,42,9,18,29,31,10,16,32,24};
	merge_s(a,0,11);
	for(i=0;i<12;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
