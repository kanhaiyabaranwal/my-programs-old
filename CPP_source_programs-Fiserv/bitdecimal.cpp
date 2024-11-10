/show decimal number
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
	int found=0;
	for(int i=0;t>0 && i<32;i++)
	{
		if(y&(1<<i))
			found=1;
		t>>=1;
		if(found)
		{
			if(t>0)
			{
				cout<<"Error, more than 1 bit set\n";
				return -1;
			}
			{
				cout<<"Bit 1 found at position "<<i+1<<endl;
				return 0;
			}
		}
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
