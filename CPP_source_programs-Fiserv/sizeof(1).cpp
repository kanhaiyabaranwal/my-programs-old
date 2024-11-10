#include<iostream>
#include<cstdio>
using namespace std;
int g(int &a)
{
	cout<<"insde f_&a\n";
	return 0;
}
int f(int a)
{
	cout<<"insde f_a\n";
	return 0;
}
int main()
{
	printf("sizeof int=%%",sizeof(int));
	int n=5;
	f(n);
	//g(n);
	return 0;
}
	
