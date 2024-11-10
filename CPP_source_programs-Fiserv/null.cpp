#include<iostream>
using namespace std;

int func(int i,int *pi,char c)
{
	cout<<"inside func\n";
	if(pi)
		cout<<"pi has value "<<*pi<<endl;
	else
		cout<<"pi is null"<<endl;
	return 0;
}

int main()
{
	cout<<"calling func with NULL\n";
	func(4,NULL,'a');
	cout<<"calling func without NULL\n";
	int i=40;
	func(4,&i,'a');
	return 0;
}

