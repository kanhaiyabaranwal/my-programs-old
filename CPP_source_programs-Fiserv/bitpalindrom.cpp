//Given an integer ?x?, write a C function that returns true if binary representation of x is palindrome else return false.
#include<iostream>
using namespace std;

bool bitPalindrome(int x)
{

	int i=31;
	//find beginning of 1st 1
	int y=x;
	int p=0;
	while(y>0)
	{
		y>>=1;
		p++;
	}
	cout<<"p="<<p<<endl;
	while(!(x&(1<<i)))
		i--;
	cout<<"i="<<i<<", x=";
	for(int m=i;m>=0;m--)
	{
		int b=(x>>m)&1;
		cout<<b;
	}
	cout<<endl;
	int j=0;
	while((i>j)&&(((x>>i)&1)==((x>>j)&1)))
	{
			i--;j++;
	}
	if(i<=j)
		return 1;
	return 0;
}

int main()
{
	int x;
	while(1)
	{
		cout<<"Enter number, 0 to exit"<<endl;
		cin>>x;
		if(x==0)
			break;
		bool isBitPalindrome=bitPalindrome(x);
		if(isBitPalindrome)
			cout<<x<<" is palindrome"<<endl;	
		else
			cout<<x<<" is not palindrome"<<endl;	
	}
	return 0;
}
