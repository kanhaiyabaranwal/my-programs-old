#include<iostream>
using namespace std;

int convert0to5(int n)
{
	int m=n;
	int mul10=1;
	while(m>0)
	{
		if(m%10==0)
			n+=(5*mul10);
		m/=10;
		mul10*=10;
	}
	return n;
}

int main()
{
	int n;
	cout<<"Enter number:";
	cin>>n;
	int out=convert0to5(n);
	cout<<"Original number is "<<n<<" and converted number is "<<out<<endl;
	return 0;
}
