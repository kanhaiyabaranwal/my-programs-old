#include<iostream>
using namespace std;

class B 
{
public:
   virtual void f(int) {std::cout << "B::f" << std::endl;}
};

class D : public B
{
public:
   virtual void f(int) override final {std::cout << "D::f" << std::endl;}
};

class F : public D
{
public:
   virtual void f(int) override {std::cout << "F::f" << std::endl;}
};

int main()
{
	F f;
	return 0;
}
