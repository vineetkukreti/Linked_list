#include<stdio.h>
int main()
{
	int n,temp,i,j;
	printf("Enter the array size: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the array elements: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
		   if(a[i]>a[j])
		  {
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
	      }
	    }
    }
	for(i=0;i<n;i++)
	{
		printf("a[i]=%d\n",a[i]);
	}
}
