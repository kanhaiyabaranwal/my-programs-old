#include<iostream>
using namespace std;

class A{
	public:
	static void func() { cout<<"Inside static func"<<endl; }
	void func(int t) { cout<<"Inside local func"<<endl; }
	void func(int t,char p) { cout<<"int="<<t<<" char="<<p<<endl; }
	void func(char p,int t) { cout<<"int="<<t<<" char="<<p<<endl; }
};

int main()
{
	A a;
	a.func(5);
	a.func();
	a.func(4,'d');
	a.func('d',3);
	return 0;
}
	
