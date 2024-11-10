#include<iostream>
using namespace std;

class X{
	public:
	int i;
	//static char p;
	X(int j):i(j) { cout<<"X's contor"<<endl; }
	X(char c)	{ cout<<"type conversion from c to X"<<endl; }
	virtual void print() {cout<<"i am in X\n";}
	X& operator=(const X& x)
	{
		cout<<"In X's op =\n";
		if(this!=&x)
			i=x.i;
		return *this;
	}
};
//char X::p='5';
class Y:public X{
	public:
	int i;
	Y(int j):i(j),X(j+1) { cout<<"Y's contor"<<endl;}
	void print() {cout<<"i am in Y\n";}
	Y& operator=(const int y)
	{
		cout<<"In Y's op int =\n";
			i=y;
		return *this;
	}
	/*Y& operator=(const Y& y)
	{
		cout<<"In Y's op Y =\n";
			i=y.i;
		return *this;
	}*/
};
//int Y::i=4;
class X1{
	public:
	X1() { cout<<"X's contor"<<endl; }
	void print() {cout<<"i am in X\n";}
};

int func(X *x)
{
	x->print();
	cout<<"value of x="<<x->i<<endl;
	cout<<"sizeof x="<<sizeof(*x);
	return 0;
}
int funchar(const Y y)
{
	cout<<"taking y as input while char was passed\n";
	return 0;
}

int main()
{
	cout<<"sizeofX="<<sizeof(X)<<endl;
	cout<<"sizeofY="<<sizeof(Y)<<endl;
	cout<<"sizeofX1="<<sizeof(X1)<<endl;
	Y y(4);
	func(&y);
	Y y1(5);
	cout<<"y.i="<<y.i<<endl;
	y=y1;
	cout<<"after change y.i="<<y.i<<endl;
	funchar('a');
	return 0;	
}
