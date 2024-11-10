#include<iostream>
using namespace std;

int func(int i,int j)
{
	cout<<"i="<<i<<",j="<<j<<endl;
	cout<<"i="<<i++<<",i++="<<i++<<endl;
	return 0;
}
int main()
{
	int k=9;
	func(k++,k++);
	return 0;
}
