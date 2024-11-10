#include<iostream>
using namespace std;

class base{
	public:
	//base(derived);	implicit conversion
};
class derived:public base{
	public:
		
};
int func(base &b)
{
	cout<<"calling base"<<endl;
	return 0;
}

int main()
{
	derived d;
	func(d);
	return 0;
}

