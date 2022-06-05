#include<stdio.h>
int main()
{
	int a,n,i=0,j;
	printf("\nEnter the number of elements : ");
	scanf("%d",&n);
	int b[n];
	printf("\nEnter the Elements : \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	printf("\nArray before Sorting : \n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",b[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			int temp;
			if(b[j]>b[j+1])
			{
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			}
		}
	}
	printf("\nArray After Sorting : \n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",b[i]);
	}
}
