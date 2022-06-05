#include<iostream>
using namespace std;
class complex1
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
			cout<<" a= "<<a<<" b= "<<b<<endl;
		}
		int geta()
		{ return a;}
		int getb()
		{ return b;}
};
class complex2
{
	private:
		int m,n;
	public:
		complex2() 
		{ 
		}
		complex2(complex1 p)
		{
			m=p.geta();
			n=p.getb();
		}
		void showdata()
		{
			cout<<" m= "<<m<<" n= "<<n<<endl;
		}
};

int main()
{
	complex1 c1;
	c1.setdata(12,45);
	complex2 c2;
	c2=c1;
	c2.showdata();
	return 0;
}
