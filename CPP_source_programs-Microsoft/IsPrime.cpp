#include<iostream>
#include<queue>
#include<cmath>
using namespace std;


bool IsPrime(int n)
{
	if(n<2)
		return false;
	if(n==2 || n==3)
		return true;
	if(n%2==0 || n%3==0)
		return false;
	int sqrt_v=sqrt(n);
	cout<<"sqrt:"<<sqrt_v<<endl;
	for(int i=5;i<sqrt_v+1;i+=2)
	{
		if(n%i==0)
			return false;
	}
	return true;
}

int main()
{
	int n=101;
	cout<<"IsPrime:"<<IsPrime(n)<<endl;
	return 0;
	
}

