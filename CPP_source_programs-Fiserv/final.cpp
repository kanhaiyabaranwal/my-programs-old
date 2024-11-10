#include<iostream>
using namespace std;

class base{
	base() {
		cout<<"inside base"<<endl;
	}
	friend int main();
};
/*class derived:public base{
	public:
		derived() {
			cout<<"inside derived"<<endl;
		}
};*/	

int main()
{
	base b;
	return 0;
}

