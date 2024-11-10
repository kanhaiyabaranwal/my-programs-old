#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

//foo object allows only on heap not on stack. Make a static method that creates an object and returns its pointer. Also, constructor is private so that stack may not create it.
class Foo
{
public:
    static Foo* createFoo()
    {
        return new Foo();
    }
private:
    Foo() {}
    Foo(const Foo&) {}
    Foo& operator=(const Foo&) {}
};

//bar object allows only on stack and not on heap. Make overloaded new private so it is not called.

class bar{
	void* operator new(size_t sz)
	{
		void* p= malloc(sz);	
		return p;
	}
	public:
	bar() {}
};


int main()
{
	//Foo f;
	Foo *f1=Foo::createFoo();

	//allowed on stack, prevented on stack
	bar b;
	bar* b1=new bar();
	return 0;
}
