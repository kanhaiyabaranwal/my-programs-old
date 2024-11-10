#include<iostream>
using namespace std;

int square(int n)
{
	if(n==1)
		return 1;
	else if(n==0)
		return 0;
	else if(n<0)		//handle negative number
		return square(-n);
	else if(n&1)		//odd number
		return square(n-1)+2*(n-1)+1;
	else 			//even number
		return (square(n>>1))<<2;
}
int main()
{
	cout<<"Enter number to find square:";
	int n;
	cin>>n;
	cout<<"Square of "<<n<<"="<<square(n)<<endl;
	return 0;
}
	
