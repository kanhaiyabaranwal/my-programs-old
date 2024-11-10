#include<iostream.h>
using namespace std;

class A{
	public:
	void print(){
		cout<<"Hello World\n";
	}
};
int main()
{
	A *a=NULL;
	a->print();
	return 0;
}
