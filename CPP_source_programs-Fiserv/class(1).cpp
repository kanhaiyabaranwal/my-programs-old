#include<iostream>
using namespace std;

class Base{
	public:
	Base() { cout<<"Base ctor\n"; }
	const Base& operator=(const Base& b)= delete;
	/*const Base& operator=(const Base& b)
	{
		cout<<"inside ="<<endl;
		return b;
	}*/
	virtual void f(){ cout<<"In Base f()\n"; }
};
class Derived{
	public:
	Derived() { cout<<"Derived ctor\n"; }
};
class A:public Base{
	private:
	void f(){ cout<<"In A f()\n"; }
	public:
	int i;
	int j;
	static int s;
	Derived d;
	public:
	A():d(),Base(),j(s++),i(s++) {}
	void printij(){
		cout<<"i="<<i<<",j="<<j<<endl;
	}
	const A& operator=(const A& a)
	{
		cout<<"inside A's ="<<endl;
		return a;
	}

};
int A::s=10;
int main()
{
	class A a;
	a.printij();
	Base *b=new A();
	b->f();
	Base c;
	c=*b;
	return 0;
}
	
