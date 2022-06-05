#include<iostream>
using namespace std;
class complex
{
    private:
	int a,b;
	public:
	void setdata(int x,int y)
	{
		a=x; b=y;	
	}	
	void showdata()
	{
		cout<<"a= "<<a<<" b= "<<b<<endl;
	}
	operator int()
	{
		return(a+b);
	}
};

int main()
{
	complex c;
	c.setdata(67,13);
	c.showdata();
	int x;
	x=c;
	cout<<"X = "<<x<<endl;
	return 0;
}
