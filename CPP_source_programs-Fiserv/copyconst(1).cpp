#include<iostream>
using namespace std;

class A{
public:
	int i;
	A(int ij):i(ij)	{ cout<<"Inside A()\n"; }
	A(const A& a)	{ i=a.i; cout<<"Insde copy A()\n"; }
	A(const A* pa)	{ i=pa->i; cout<<"Insde copy22 A()\n"; }	//will it be constructor conversion? Doesn't seem so.
};

int main()
{
	A a(4);
	A b=a;
	A c(&a);
	cout<<"value of c.i="<<c.i<<endl;
	cout<<"value of b.i="<<b.i<<endl;
	return 0;
}

