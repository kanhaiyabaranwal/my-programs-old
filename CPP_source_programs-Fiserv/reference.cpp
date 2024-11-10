#include<iostream>
using namespace std;

int& f()
{
	int i=0;
	return i;
}
int main()
{
	int i=2;
	const int j=3;
	
	const int &ri=4;
	const int &rj=j;
	//ri=rj;
	cout<<"ri="<<ri<<endl;
	f();
	return 0;
}
