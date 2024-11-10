#include<iostream>

using namespace std;


class X{
	int val;
	public:
	
	X(int i=0):val(i) {
		cout<<"Inside X contructor\n";
	}
	friend ostream& operator<<(ostream &os, X& x){
		
		os<<"overloaded <<;  "<<x.val<<endl;
		return os;
	}
	int getVal(){
		return val;
	}
	~X(){
		cout<<"Inside X detructor\n";
	}
};

template<class T>
class my_auto_ptr{
	T* obj;
	public:
	my_auto_ptr(T* objpass):obj(objpass) {}
	
	T& operator*(){
		cout<<"Inside overloaded *operator\n";
		if(obj)
		return *obj;
	}
	
	T* operator->(){
		return obj;
	}
	//transfer of ownership- copying an auto-pointer to another pointer is actually transfer, i.e. create new obj and delete old object
	
	
	/*friend ostream& operator<<(ostream &os, my_auto_ptr& my_ptr){
		os<<my_ptr.obj<<endl;
		return os;
	}*/
	
	~my_auto_ptr(){ 
		cout<<"deleting object from auto_ptr\n";
		delete obj;
	}
	
};

void print(my_auto_ptr<X>& x)
{
	cout<<"x="<<x->getVal()<<endl;
	return;
}

int main(){
	cout<<"Implment auto_ptr\n";
	X *x = new X(40);
	cout<<"value in X="<<x->getVal()<<endl;
	cout<<"value in X="<<(*x).getVal()<<endl;
	my_auto_ptr<X> myptr(static new X(40));
	//cout<<"value in my_auto_ptr="<<(*myptr).getVal()<<endl;
	cout<<"calling function getVal"<<myptr->getVal()<<endl;
	//myptr->getVal();
	print(myptr);
	
	//myptr
	return 0;
	
}
