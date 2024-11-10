#include<iostream>


class D;
	

class C{
	C() {
	}
	friend class D;
};

class D{
	C c;
	public:
		
};

int main()
{
	D d;
	return 0;
}
