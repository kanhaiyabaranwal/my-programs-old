#include<iostream>
#include<typeinfo>
using namespace std;

class A{
	
};
class B:public A{};

int main(){
	A * a=new B;
	
	cout<<"type of a is "<<typeid(a).name()<<endl;
	return 0;
}
