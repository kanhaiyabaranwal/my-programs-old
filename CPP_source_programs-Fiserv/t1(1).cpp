#include<iostream>
using namespace std;
class test
{  
int i;  
	public: 
	test()	{cout<<"inside ctor\n"; }
	~test()	{cout<<"inside dtor\n"; }
int print() 
{ 
	cout << "value of I = "<<i<<endl; 
	//delete this; 
	return 0;
}
int increment () { i++ ;return 0;}
};
int main()
{  //test t; t.increment(); t.print(); t.increment() ; t.print(); 
	int a = 10; 
	int I = 100; 
	int &j = I; 
	int &k = j;
	 k++;
	 cout <<"a="<<a<<I <<j <<k <<endl;
	 char *p = "Hello";
	*p='M';
	//p="Happy";
	cout<<p<<endl;
}

