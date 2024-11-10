#include<iostream>

using namespace std;



void fun1(int i,int j)
{
	int k;int l;
	if (&i < &j )
		cout<<"downward in fun1"<<endl;
	else
		cout<<"upward in fun1"<<endl;
	
	if (&k < &l )
		cout<<"downward in local fun1"<<endl;
	else
		cout<<"upward in local fun1"<<endl;
}

void fun()
{
	int j;
	int i;
	if (&i < &j )
		cout<<"downward in fun"<<endl;
	else
		cout<<"upward in fun"<<endl;
	fun1(i,j);
}

int main()
{
	fun();
	return 0;
}
