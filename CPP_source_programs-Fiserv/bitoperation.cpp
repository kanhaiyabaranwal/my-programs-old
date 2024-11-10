//show decimal number
#include<iostream>
using namespace std;

bool bitdisplay(double x)
{

	cout<<"x=";
	double temp1=x;
	cout<<"0.";
	for(int m=63;temp1>0 && m>=0;m--)
	{
		temp1=temp1*2;
		if(temp1>=1)
		{
			temp1-=1;
			cout<<1;
		}
		else
			cout<<0;
	}
	cout<<endl;
	return 0;
}

void	bitoperation(int x)
{
	cout<<"Subtract"<<endl;
	cout<<"x="<<x<<",~x="<<~x<<",-x="<<~x+1<<endl;
}
int main()
{
	double x;
	int y;
	while(1)
	{
		cout<<"Enter number < 1, 0 to exit"<<endl;
		cin>>x;
		if(x==0)
			break;
		bitdisplay(x);
		bitoperation(x*100);
	}
	return 0;
}
