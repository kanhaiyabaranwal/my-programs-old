//Swap two nibbles in a byte
#include<iostream>
using namespace std;

bool swapnibble(int x)
{

	cout<<"x=";
	for(int m=31;m>=0;m--)
	{
		int b=(x>>m)&1;
		cout<<b;
	}
	cout<<endl;
	int y=((x&15)<<4) | (x>>4);
	cout<<"y=";
	for(int m=31;m>=0;m--)
	{
		int b=(y>>m)&1;
		cout<<b;
	}
	cout<<endl;
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
		swapnibble(x);
	}
	return 0;
}
