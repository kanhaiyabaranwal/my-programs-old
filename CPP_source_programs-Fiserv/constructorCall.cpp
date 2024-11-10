#include<iostream>
using namespace std;

class X{
public: 
	X() {cout<<"X's contructor\n"; }
	~X() {cout<<"X's detructor\n"; }
};
class A{
	int i;
public:
	A(int j):i(j) {cout<<"A's contructor\n"; }
	~A() {cout<<"A's detructor\n"; }
	A& operator+=(const A& a){
		cout<<"Inside A's += operator"<<endl;
		i+=a.i;
		return *this;
	} 
	int geti() const	{ return i;}
	friend ostream& operator<<(ostream& os, const A& a)
	{
		os<<a.i;
		return os;
	}
};
class B:public A{
	X x;
public:
	B(int j):x(),A(j) {cout<<"B's contructor\n"; }
	~B() {cout<<"B's detructor\n"; }
};

int main()
{
	//A a;
	B b(2),c(3);
	cout<<"c="<<c<<" and b="<<b<<endl;
	c+=b;
	cout<<"c after change="<<c<<endl;
	return 0;

}
