#include<iostream>
#include<memory>
using namespace std;
class X{
	int i;
	public:
		X(int h):i(h)	{
			cout<<"X contructor"<<endl;
		}
		~X()	{
			cout<<"X detructor"<<endl;
		}
		int geti() {
			return i;
		}
};


int main()
{
	auto_ptr<X> i(new X(4));
	cout<<"i="<<i->geti()<<endl;
	return 0;
}
