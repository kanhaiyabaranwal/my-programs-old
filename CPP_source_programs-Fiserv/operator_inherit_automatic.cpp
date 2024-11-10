#include<iostream>

using namespace std;

class base{
	int i;
	public:
	base(int j):i(j) {}
	bool operator==(const base& b)
	{
		return i==b.i;
	}
};
class derived:public base{
	public:
	derived(int j):base(j) {}
};

int main()
{
	derived d1(4),d2(5),d3(4);
	if(d1==d2)
		cout<<"values are same"<<endl;
	else	
		cout<<"values are not same"<<endl;
	if(d1==d3)
		cout<<"values are same"<<endl;
	else	
		cout<<"values are not same"<<endl;
	return 0;
}	
