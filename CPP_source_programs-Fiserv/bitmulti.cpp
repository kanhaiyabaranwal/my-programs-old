//Swap two nibbles in a byte
#include<iostream>
using namespace std;

bool bitoperation(int x,int y)
{

	cout<<"x=";
	for(int m=31;m>=0;m--)
	{
		int b=(x>>m)&1;
		cout<<b;
	}
	cout<<endl;
	cout<<"y=";
	for(int m=31;m>=0;m--)
	{
		int b=(y>>m)&1;
		cout<<b;
	}
	cout<<endl;
	int t=y;
	int m=0;
	for(int i=0;t>0 && i<32;i++)
	{
		m+= (((y&(1<<i))>>i)&1?x:0)<<i;
		t>>=1;
	}
	cout<<"mul="<<m<<endl;
	return 0;
}

int main()
{
	int x,y;
	while(1)
	{
		cout<<"Enter number, 0 to exit"<<endl;
		cin>>x;
		cout<<"Enter number, 0 to exit"<<endl;
		cin>>y;
		if(x==0)
			break;
		bitoperation(x,y);
	}
	return 0;
}
