#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	char name[]="Kanhaiya";
	char *p=new char[sizeof(name)];
	cout<<"new string is "<<*p<<" with size="<<sizeof(p)<<endl;
	printf("Address of name is %p and p is %p\n",name,p);
	cout<<"address of name is "<<(int)name<<endl;
	cout<<"address of p is "<<(int)p<<endl;
	return 0;
}
