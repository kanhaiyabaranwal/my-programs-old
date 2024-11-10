#include<iostream>
using namespace std;

int main()
{
	cout<<"Bit Insertion of M into N at position i through position j"<<endl;
	int k=2,l=6;
	int n=1110;
	int m=23;
	cout<<"m,23=";
	for(int i=31;i>=0;i--)
	{
		int m1=(m&(1<<i))>>i;
		cout<<m1;
	}
	cout<<endl;
	m<<=k;
	cout<<"newm=";
	for(int i=31;i>=0;i--)
	{
		int m1=(m&(1<<i))>>i;
		cout<<m1;
	}
	cout<<endl;
	int p=0;
	for(int t=2;t<l+1;t++)
	{
		p|=(1<<t);
	}
	cout<<"   p=";
	for(int i=31;i>=0;i--)
	{
		int p1=(p&(1<<i))>>i;
		cout<<p1;
	}
	cout<<endl;
	cout<<"1110=";
	for(int i=31;i>=0;i--)
	{
		int n1=(n&(1<<i))>>i;
		cout<<n1;
	}
	cout<<endl;
	int n4=n&p;			//n4 will be used for xoring with n
	int n5=n^n4;
	cout<<"n^n4=";
	for(int i=31;i>=0;i--)
	{
		int n1=(n5&(1<<i))>>i;
		cout<<n1;
	}
	cout<<endl;
	cout<<"after insertion=";
	int n2=n|m;
	for(int i=31;i>=0;i--)
	{
		int n3=(n2&(1<<i))>>i;
		cout<<n3;
	}
	cout<<endl;
	return 0;
}
