#include<iostream>

using namespace std;

class base{
	public:
	base()	{cout<<"inside base\n";}
	base(int i) { cout<<"i="<<i<<endl; }
	base(int i,int j,int k=0) { cout<<"ij="<<endl; }
	//base(int i,int j) { cout<<"ij="<<endl; }
	int Add(int a,int b)	{cout<<"inside base's Add"<<endl; return a+b;}
};
class derived:public base{
	public:
	derived() {cout<<"inside derived\n";}
	derived(const derived& )	{cout<<"inside copy constructor\n";}
	int Add(char c,char d)	{return c+d;}
};
int main()
{
	base* b= new derived() ;
	b->Add(3,4);
	derived d1;
	derived d=d1;
	base b1(10);
	base b2(1,10);
	return 0;
}
	
