#include<iostream>
using namespace std;

class Distance{
	private:
		int feet;
		float inches;
	public:
		void setdist(int ft,float in){
			feet=ft;
			inches=in;
		}
		void getdist(){
			cout<<"enter feet= ";
			cin>>feet;
			cout<<"enter inches= ";
			cin>>inches;
		}
		void showdist(){
			cout<<feet<<"\'-"<<inches<<'\"';
		}
};
 int main()
 {
 	Distance d1,d2;
 	
 	d1.setdist(11,6.25);
 	d2.getdist();
 	
 	cout<<"\nd1= ";
 	d1.showdist();
    cout<<"\nd2= ";
	d2.showdist();
	cout<<endl;
	return 0;	 
 }

