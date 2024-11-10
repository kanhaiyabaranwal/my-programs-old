#include<iostream>

using namespace std;

class base{
	public:
	int i;
	
		base(int val):i(val){
		}
		int getI() const{
			return i;
		}
};
int func(const base& b){
	cout<<"val="<<b.getI()<<endl;
	base b1=const_cast<base&>(b);
	b1.i=5;
	return 0;
	
}

int main()
{
	func(base(4));
	return 0;
	
}
