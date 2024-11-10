//binary representation of a decimal value
#include<iostream>
using namespace std;

int main()
{
	double val;
	cout<<"Enter number ";
	cin>>val;
	cout<<"binary representation of number "<<val<<" =0.";
	double temp=val;
	int count=0;
	do
	{
		temp*=2;
		if(temp>=1)
		{
			cout<<1;
			temp-=1;
		}
		else
		{
			cout<<0;
		}
		count++;
		if(count>64)
		{
			cout<<"Threshold of 64 digits crossed"<<endl;
			break;
		}

	}while(temp>0.0);
	cout<<endl<<"Binary representation over"<<endl;
	return 0;
}	
