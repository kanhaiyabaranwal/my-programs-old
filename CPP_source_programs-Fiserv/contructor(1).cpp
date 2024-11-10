#include <iostream> 
using namespace std;
class Test { 
private:     int x;
	int func()
	{ 
		cout<<"inside func\n";
		return 0;
	}
	friend class TestDerived;
 public:     
	Test() {}
	Test(int i)     {         
	x = i;
       cout << "Test Called" << endl;
     } 
	const Test& operator=(const Test& t)
	{
		cout<<"Inside assignment operator\n";
		return t;
	}
};
class TestDerived{
	Test t;
public:
TestDerived(Test j)
{
	t=j;
	cout << "TestDerived Called" << endl;
	t.func();
}
};

int main() {     
	Test t1(3);
	TestDerived t(t1);
     //t = 30;
 // conversion constructor is called here.     return 0;
 }
