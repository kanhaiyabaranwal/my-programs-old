//Swap two nibbles in a byte
#include<iostream>
using namespace std;

bool bitsetKthbit(int x)
{

	cout<<"x=";
	for(int m=31;m>=0;m--)
	{
		int b=(x>>m)&1;
		cout<<b;
	}
	cout<<endl;
	cout<<"Resetting 3rd bit\n";
	int k=3;
	int y=x&(~(1<<(k-1)));
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
		bitsetKthbit(x);
	}
	return 0;
}
