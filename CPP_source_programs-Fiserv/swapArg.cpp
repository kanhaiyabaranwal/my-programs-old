#include<iostream>

using namespace std;

class X{
	public:
		X() {
			cout<<"I am class X obj";
		}
};
class Y{
	public:
		Y(){
			cout<<"I am class Y obj";
		}
};

int func(X &x,Y &y)
{
	cout<<"in func\n";
	return 0;
}
int func1(Y &y, X &x)
{
	cout<<"in func1\n";
	return 0;
}

int main()
{
	X x;
	Y y;
	func(x,y);
	func1(y,x);
	return 0;
}

