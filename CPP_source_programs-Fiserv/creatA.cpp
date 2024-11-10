#include<iostream>

using namespace std;

class A{
	A() { 
		cout<<"A contructor"<<endl;
	}
	static A* a;
	public:
	
		static A& createA();
};

A* A::a=NULL;
A& A::createA()
{
	a= new A();
	return *a;
}

int main()
{
	A::createA();
	A::createA();
	return 0;
}
