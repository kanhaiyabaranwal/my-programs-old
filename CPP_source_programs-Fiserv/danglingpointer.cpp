#include<iostream>
using namespace std;

int *getX()
{
	int y=6;
	int *p=&y;
	cout<<"local stack pointer p="<<*p<<endl;
	delete p;
	int x=5;
	return &x;
}

int main()
{
	int *p=getX();
	cout<<"dangling pointer *p="<<*p<<endl;
	return 0;
}
