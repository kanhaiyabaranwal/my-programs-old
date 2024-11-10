#include<iostream>
using namespace std;

int fib(int n)
{
	int fib_prev2=0, fib_prev1=1;	//fib(0)=0, fib(1)=1
	cout<<"0,1,";
	int fib=0;
	for(int i=2;i<n;i++)
	{
		fib=fib_prev1+fib_prev2;
		cout<<fib<<", ";
		fib_prev2=fib_prev1;
		fib_prev1=fib;
	}
	cout<<"\nDone fibonacci series\n";
	return 0;
}

int main()
{
	cout<<"Show fibs\n";
	fib(15);
	return 0;
}
