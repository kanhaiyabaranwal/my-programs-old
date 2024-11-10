#include<iostream>
using namespace std;

void printWithoutLoop (int m)
{
	static int n=m;
	static bool flag=true;
	if(m>n)
		return;
	cout<<m<<",";
	if(m<0)
		flag=false;	
	if(flag)
		printWithoutLoop(m-5);
	else
		printWithoutLoop(m+5);
	
	return;	
}
int main()
{

	printWithoutLoop (16);
	return 0;
}
