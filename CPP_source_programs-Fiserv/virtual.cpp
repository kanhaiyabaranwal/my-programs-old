#include<iostream>
using namespace std;

class A{
	public:
	A(){
		func();
	}
	virtual void func()=0;
};
class B:public A{
	void func()
	{
		cout<<"I am B"<<endl;
	}
};
int main()
{
	B b;
	return 0;
}
