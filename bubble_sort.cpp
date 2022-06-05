#include<iostream>
using namespace std;

int main()
{
	int n;
	cout<<"Enter the number of element : ";
	cin>>n;
	
	int a[n];
	cout<<"Enter array elements : "<<endl;
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	cout<<"Unsorted array"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"	";
	}
	cout<<endl;
	int counter=1;
	while(counter!=n-1)
	{
		for(int i=0;i<n-counter;i++)
			{
				if(a[i]>a[i+1])
				{
					int temp=a[i];
					a[i]=a[i+1];
					a[i+1]=temp;
				}
			}
		counter ++;
	}
	//printing sorted array
	cout<<"Sorted array"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"	";
	}
	
	return 0;
}
