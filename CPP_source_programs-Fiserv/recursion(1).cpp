#include<iostream>
using namespace std;

int f(int n)
{
	if(n==0)
		return 0;
	if(n<=1)
		return 1;
	return f(n/2)+n;
}

int main()
{
	int n;
	int out;
	cout<<"enter number\t";
	while(cin>>n)
	{
		cout<<"Output= "<<f(n)<<endl;
		cout<<"Enter next number";
	}
	return 0;
}
