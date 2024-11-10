#include<iostream>

class A{
	
};

class B{
	
};

void operator+(A &a,B &b)
{
	std::cout<<"Adding A and B"<<std::endl;
}

int main()
{
	A a;
	B b;
	b+a;
	return 0;
}
