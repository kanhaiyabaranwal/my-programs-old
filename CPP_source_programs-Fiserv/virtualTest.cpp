#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
class Derived;
class Base{
	int i;
	public:
		Base(const Base& ){
			cout<<"Base copy contructor\n";
		}
		Derived& operator=(const Base& b){
			cout<<"inside Base =\n";
		}
		Base(int k):i(k){
			cout<<"Base contructor\n";
		}
		Base(){
			cout<<"Base contructor\n";
		}
		virtual int get() {
			return 12;
		}
};

class Derived:public Base{
	int i;				//this i is visible to derived only, it should not be visible when pointer of type Base calls virtual function get()
	public:
		/*Derived& operator=(const Derived& b){
			cout<<"inside derived =\n";
		}*/
		/*Derived& operator=(const Base& b){
			cout<<"inside base derived =\n";
		}*/
		Derived(int ik):i(ik)	{
			cout<<"inside derived contructor\n";
		}
		Derived(const Derived& d):Base(d){
			cout<<"Derived copy contructor\n";
		}
		int get() {
			return i;
		}
};

int main()
{
	Base *b= new Derived(4);
	//cout<<"Value of get is "<<b->get()<<endl;
	free(b);
	return 0;
	Base b1;
	//b1=*b;
	Derived d2(4);
	Derived d1=d2;
	//d2=b1;
	return 0;
}
