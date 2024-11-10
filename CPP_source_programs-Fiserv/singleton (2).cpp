#include<iostream>
using namespace std;
class Singleton{
	static Singleton s;
	int mem;
	Singleton(int x):mem(x) {cout<<"inside Singleton with int arg\n";}
	Singleton():mem(0)  {cout<<"inside Singleton with no arg\n";}
	Singleton(const Singleton &s) {cout<<"inside copy constructor\n";}
public:
	static Singleton& instance()	{ cout<<"inside instance\n";return s;}
	int value()	{ cout<<"inside value"<<s.mem<<"\n";return s.mem;}
	static void Setval(int x)	{s.mem=x;}
};
Singleton Singleton::s(4);
int main()
{
	Singleton::instance().value();
	Singleton::Setval(6);
	Singleton::instance().value();
	//Singleton s1;
	//Singleton *s2=new Singleton();
	return 0;
}

