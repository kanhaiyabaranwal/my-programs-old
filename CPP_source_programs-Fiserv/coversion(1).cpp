#include <iostream>

using namespace std;

class A{
	int val;
	public:
	A(int i):val(i)	{ cout<<"inside ctor A\n"; }
	~A()	{cout<<"inside dtor A\n";}
	operator int(){
		return val;
	}
};
int func(A a)
{
	cout<<"Accepting A while passing int"<<endl;
	return 0;
}
int main()
{
	A a(4);
	int me=a;
	cout<<"me="<<me<<endl;
	func(4);
	a.~A();
	a.~A();
	return 0;
}
	
	
