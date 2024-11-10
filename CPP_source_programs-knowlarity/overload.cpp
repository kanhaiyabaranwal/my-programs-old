#include<iostream>
using namespace std;

class base{
	public:
	base(){
		cout<<"base int constructor"<<endl;
	}
	virtual int func(int a)
	{
		cout<<"base func with int return"<<endl;
		return 0;
	}
};
class derived:public base{
	public:
	int func(int a)
	{
		cout<<"derived func with char return"<<endl;
		return 0;
	}
	derived()
	{
		cout<<"default derived constructor"<<endl;
	}
	derived(const base& b)
	{
		cout<<"inside derived copy constructor"<<endl;
	}
};

class myclass{
	public:
	void myfunc(const base& b)
	{
		cout<<"Taking base b"<<endl;
	}
	void myfunc(const derived& b)
	{
		cout<<"Taking derived b"<<endl;
	}
};

int main()
{
	base* b=new derived();
	b->func(4);
	myclass mc;
	const derived& rb=derived(*b);
	mc.myfunc(rb);
	return 0;
}	
