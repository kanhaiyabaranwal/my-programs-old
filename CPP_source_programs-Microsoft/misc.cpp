#include<iostream>
using namespace std;

class Singleton{
	Singleton(int i): num(i) {}
	Singleton(Singleton& s) = delete;
	int num;
	public:
	static Singleton s;
	int val(){ return s.num;}
};
Singleton Singleton::s(45);


class Base{
	public:
		int i;
		Base(int i):i(i){
		}
		void print(){
			cout<<"i is "<<i<<endl;
		}
};
void increment(int*& i) { i++; }
int main()
{
	
	int* i = 0;
	cout << "i = " << i << endl;
	increment(i);
	cout << "i = " << i << endl;

	Base b(4);
	Base *c=&b;
	c->print();
	cout<<"Value of singleton member is " <<Singleton::s.val()<<endl;

	return 0;
}
