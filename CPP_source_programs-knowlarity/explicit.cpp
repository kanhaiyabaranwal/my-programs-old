#include<iostream>
using namespace std;


class A{
	public:
	explicit A() { cout<<"Inside A's con'tor\n"; };
};
class B:public A{
	public:
	explicit B() { cout<<"Inside B's con'tor\n"; }
	//virtual void f(B a) { cout<<"Calling f from B"<<endl }
};
	
void f(B a) { cout<<"Calling f from a"<<endl; }


void explicit1 ()
{
	B b;
	A a;
	f(a);

}
int main()
{

	explicit1 ();
	return 0;
}
