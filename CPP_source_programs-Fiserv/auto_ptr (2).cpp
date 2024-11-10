#include<iostream>
#include<memory>
using namespace std;

class A{
	int i;
	
	public:
	A(int j):i(j) { cout<<"Inside A's contrutor\n"; }
	~A() { cout<<"Inside A's detructor\n"; }
	int geti()	{ return i; }
};
int main()
{
	auto_ptr<A> a(new A(4));
	cout<<"a->i="<<a->geti()<<endl;
	
	return 0; 
}
