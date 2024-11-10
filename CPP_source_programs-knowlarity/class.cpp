#include<iostream>
using namespace std;

class A{
	int a;
	const int b;
	static int c;
	char *pch;
		
	public:
	A():b(0) 
	{ 
		cout<<"inside A"<<endl;
	}
};
class B:public A{
	double d;
	public:
	B() 
	{ 
		cout<<"inside B"<<endl;
	}
};

class C:public B{
	A a;
	public:
	C() 
	{ 
		cout<<"inside C"<<endl;
	}
};

int main()
{
	cout<<"Sizeof A:"<<sizeof(A)<<endl;
	cout<<"Sizeof B:"<<sizeof(B)<<endl;
	C c;
	return 0;
}

