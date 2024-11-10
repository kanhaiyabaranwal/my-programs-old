#include<iostream>
using namespace std;

class Cl{
	int num;
	public:
	Cl(int n=0):num(n)	{cout<<"inside ctor"<<endl;}
	Cl(const Cl& c):num(c.num)	{cout<<"inside cctor"<<endl;}
	Cl& operator =(Cl& c1)	{cout<<"inside ="<<endl; this->num=c1.num;	return *this; }
};

static int& funct() { 
	static int x=4; 
	cout<<"x="<<x<<endl; 
	return x;
}
int main()
{
	Cl c1(2),c2(3);
	c2=c1;
	Cl c3=c2;
	int &x=funct();
	x++;
	cout<<"static x="<<x<<endl;
	x=funct();
	cout<<"static x="<<x<<endl;
	return 0;
}
	
