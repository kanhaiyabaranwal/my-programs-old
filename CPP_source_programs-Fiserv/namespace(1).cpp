#include<iostream.h>

namespace n1 {
	int a1;
}

namespace n2 {
	int a1;
}

int main()
{
	using namespace n2;
	n1::a1=4;
	cout<<"a1="<<n1::a1<<endl;
	a1=5;
	cout<<"n2::a1="<<a1<<endl;
	return 0;
}
