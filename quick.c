#include<stdio.h>
quick(int b[],int low,int high)
{
	int temp;//i,j,pivot;
	int pivot=b[low];
	int i=low+1;
	int j=high;
	if(low<high)
	{
		while(i<=j)
		{
			while(b[i]<pivot)
				i++;
			while(b[j]>pivot)
				j--;
			if(i<j)
			{
				temp=b[i];
				b[i]=b[j];
				b[j]=temp;
			}
			else
				break;
		}
		temp=b[low];
		b[low]=b[j];
		b[j]=temp;
		quick(b,low,j-1);
		quick(b,j+1,high);
	}
}
int main()
{
	int i, a[]={25,27,13,42,9,18,29,31,10,16,32,24};
	quick(a,0,11);
	for(i=0;i<12;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}

