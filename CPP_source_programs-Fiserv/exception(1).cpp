#include <iostream>
#include <exception>
#include <stdexcept>
#include <typeinfo>
using namespace std;
class myexception:public exception{
	public:
	const char* what() const throw()
	{
		return "my exception";
	}
} myex;

class A {};
class B:public A{};

int main()
{
	B b;
	A *a=&b;
	cout<<"type is "<<typeid(*a).name()<<endl;
	int x[20];
	cout<<"type is "<<typeid(x).name()<<endl;
	try{
		int r1=0;
		int r2=400/r1;
		cout<<"r2="<<r2<<endl;
		
		throw runtime_error("caught runtime error");
	}
	catch(runtime_error &e)
	{
		cout<<"error type="<<typeid(e)<<" error= "<< e.what();
	}
	catch(exception &e)
	{
		cout<<e.what();
	}
	catch(...)
	{
		cout<<"exception not defined\n";
	}
	return 0;
}
