#include<iostream>
#define __IBMCPP_TR1__ 1
using namespace std;
//using namespace std::tr1;

class Base{
	int i;
	public:
	Base(int j):i(j) {}
	const int& operator()() const {
		return i;	
	}
};
int main()
{
	Base b(5);
	Base& c=b;
	Base&& d=Base(6);
	cout<<"value of b="<<b()<<endl;
	cout<<"value of c="<<c()<<endl;
	return 0;
}
