#include<iostream>
using namespace std;

class A{
	int i;
	public:
		A(int i):i(i){
		}
		A& operator=(const A& a){
			if(this==&a)
				return *this;
			i=a.i;
		}
		int geti(){
			return i;
		}
};

int main()
{
	A a(4);
	A b(5);
	b=a;
	cout<<b.geti();
	
}
