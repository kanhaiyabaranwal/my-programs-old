#include<iostream>
#include<typeinfo>
using namespace std;

class A{
};
class B:public A{
};
class Base{
	/*int m;
	int i;
	int p;
	int k;
	int n;
	*/
	public:
	virtual A* func(int i)
	{
		cout<<"Base with int"<<endl;
		A *b=new A();
		return b;
	}
	virtual int func(int i,char c)
	{	
		cout<<"Base with int and char"<<endl;
		return 0;
	}
};
class Derived: public Base{
	public:
	char j;
	char l;
	enum sz{zero,one,two };
		Derived() {
			cout<<"Setting the member values";
		}
	/*int func(int i)
	{
		cout<<"Derived with int"<<endl;
		return 0;
	}*/
	B* func(int i)
	{
		cout<<"Derived with return char"<<endl;
		B* a=new B();
		return a;
	}
};

int main(){
	Base *d=new Derived();
	//d->func(4,'s');
	Derived *d1=dynamic_cast<Derived*>(d);
	d1->func(5);
	//cout<<"typeid(d)="<<typeid(d)<<endl;
	cout<<"sizeof Base="<<sizeof(Base)<<" size of Derived="<<sizeof(Derived)<<endl;
	d->func(4);
	return 0;
}
