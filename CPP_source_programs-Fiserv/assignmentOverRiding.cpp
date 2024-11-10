#include<iostream>
#include<string>
using namespace std;

class Base{
	
	public:
		int k;
		Base(int j):k(j)	{
		}
		Base& operator=(const Base& b) {
			cout<<"Inside Base operator,k="<<k<<endl;
			if(this!=&b)
				k=b.k;
			return *this;
		}
		Base(const Base& b){
			cout<<"inside base's copy constructor"<<endl;
		}
};

class Derived:public Base{
	int i;
	//Base b;
	public:
		Derived(int j):i(j),Base(j)	{
			cout<<"construct Derived"<<endl;
		}
		Derived& operator=(const Derived& b) {
			cout<<"Inside Derived operator,i="<<i<<endl;
			if(this!=&b)
				i=b.i;
			return *this;
		}
		Derived(const Derived& d):Base(d){
			cout<<"inside Derived copy constructor"<<endl;
		}
		Derived& operator++(){
			i++;
			return *this;
		}
		int geti() {
			return i;
		}
		int getk(){
			return k;
		}
		friend Derived operator+(const Derived& d1, const Derived& d2);
		friend Derived operator+(const Derived& d1, int i);
		friend ostream& operator<<(ostream& os,const Derived &d);
};
Derived operator+(const Derived& d1, const Derived& d2) {
	return Derived(d1.i+d2.i);
}
Derived operator+(const Derived& d1, int i) {
	return Derived(d1.i+i);
}
ostream& operator<<(ostream& os,const Derived &d){
	os<<d.i;
	return os;
}

class X {
	public:
	X(){
		cout<<"X contructor"<<endl;
	}
	X(const X& ){
		cout<<"X copy contructor"<<endl;
	}
	X& operator=(const X& x2){
		cout<<"X assignment operator"<<endl;
		return *this;
	}
	~X(){
		cout<<"X destructor"<<endl;
	}
	
};
X f5(){
	
	return X();
}
void f6(const X&){
	cout<<"inside f6";
}
const string func(){
	return "kanhaiya";
}

class Number{
	int num;
	public:
		virtual int operator+() const{ 
		cout<<"inside Base";
		return this->num;}
};
class MyNumber:public Number{
	int num;
	public:
		int operator+() const{ 
		cout<<"inside derived";
		return this->num;}
};


int main(){
	Number *n=new MyNumber;
	cout<<+(*n)<<endl;
	
	const string &str=func();
	//f5()=X();
	cout<<"Calling f6...";
	f6(f5());
	cout<<"End of Calling f6...";
	//Derived d(3);
	//Derived e(4);
	//cout<<"e.i="<<e.geti()<<"e.k="<<e.getk()<<endl;
	//e=d;
	Derived d=Derived(3);
	Derived e=d;
	//cout<<"e.i="<<e.geti()<<"e.k="<<e.getk()<<endl;
	//++(++e);
	//Derived f(5);
	//cout<<"result sum="<<++(d+e)<<endl;
	//cout<<"result sum="<<++(13+d)<<endl;
	return 0;
}

