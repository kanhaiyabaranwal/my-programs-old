#include<iostream>
#include<string>
using namespace std;

class Number{
	int i;
	public:
		Number(int n):i(n){
		}
	friend Number operator+(const Number& n1, const Number& n2){
		return Number(n1.i+n2.i);
	}
	friend Number& operator++(Number& n){
		n.i++;
		return n; 
	}
	const int getI() const {
		return i;
	}
	
};

int main()
{
	Number n1(4),n2(5);
	Number n3=n1+n2;
	++n3;
	cout<<"result of sum="<<n3.getI()<<endl;
	int *p;
	int& ref=*p;
	cout<<"ref="<<ref<<endl;
	return 0;
}
