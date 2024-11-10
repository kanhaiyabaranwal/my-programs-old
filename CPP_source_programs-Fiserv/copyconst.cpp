#include<iostream>
using namespace std;

class A{
public:
	int i;
	A():i(0){
		cout<<"Inside A() contructor\n";
	}
	A(int ij):i(ij)	{ cout<<"Inside A()\n"; }
	A(const A& a)	{ i=a.i; cout<<"Insde copy A()\n"; }
	A(const A* pa)	{ i=pa->i; cout<<"Insde copy22 A()\n"; }	//will it be constructor conversion? Doesn't seem so.
	//A(A ()	{ i=a.i; cout<<"insde argument by value"; }
	A& operator[](int i){
		cout<<"inside [] ";
		return *(this+i);
	}
};

int main()
{
	//A a(4);
	//A b=a;
	//A c(&a);
	A arr[5];
	A m=arr[2];
	//cout<<"value of c.i="<<c.i<<endl;
	//cout<<"value of b.i="<<b.i<<endl;
	//cout<<"value of d.i="<<d.i<<endl;
	return 0;
}

