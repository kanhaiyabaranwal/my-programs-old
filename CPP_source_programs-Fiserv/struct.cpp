#include<iostream>

using namespace std;

struct Base{
	char b;
};
struct Derived:public Base{
	double dd;
	char d;
};
int main()
{
	Derived d;
	cout<<"sizeof Base struct="<<sizeof(Base)<<endl;
	cout<<"sizeof Derived struct="<<sizeof(Derived)<<endl;
	return 0;
}

