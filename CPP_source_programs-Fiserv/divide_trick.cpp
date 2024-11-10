#include<iostream>
using namespace std;

void divide(int x,int y)
{
	int num=y;
	int n=0;
	int flag=0;
	while(num<x)
	{
		flag=1;
		num<<=1;
		if(n)
			n<<=1;
		else
			n=1;
	}
	if(flag)
		num>>=1;
	int res=x-num;
	while(res>y)
	{
		res-=y;
		n++;
	}
	cout<<"quotient ="<<n<<", remainder="<<res<<endl;
}
int main()
{
	int x,y;
	cout<<"Enter dividend\n";
	cin>>x;
	cout<<"Enter divisor\n";
	cin>>y;
	divide(x,y);
	return 0;
}
